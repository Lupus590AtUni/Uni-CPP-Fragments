#include "NA_MathsLib.h"
#include <math.h>//used to generate lookup tables at start of program
#include "NA_Vector.h"
#include "NA_Matrix.h"
#include <random>
#include <time.h>

const float NA_MathsLib::PI = 3.14f;//this is a stupid compiler rule in my opinion

NA_MathsLib maths; //contructs itself, access with extern NA_MathsLib maths;

NA_MathsLib::NA_MathsLib(void)
{
  debug = false;
}

NA_MathsLib::~NA_MathsLib(void)
{
}

void NA_MathsLib::seedDice()
{
	srand(time(NULL));
	//srand(0); //use for testing
}

void NA_MathsLib::seedDice(unsigned int seed)
{
	srand(seed);
}

int NA_MathsLib::dice(int bottom, int top)
{
	//https://answers.yahoo.com/question/index?qid=20100615173601AAMHzBy
	return (rand() % ((top + 1) - bottom)) + bottom;//between bottom and top, inclusive
}

int NA_MathsLib::dice(int top)
{
	return (rand() % (top+1)); //between 0 and top, inclusive
}



void NA_MathsLib::init()//fill the lookup tables
{
	if(!NA_USE_OTHER_TRIG)
	{
		if(debug) cout<<"Filling trig lookup tables\n";
		for(int i=0; i<NA_M_LOOKUP_MAX; i++)//walk through lookup table assigning values from math.h
		{
			sinLookup[(int)i] = (float) sinf(degToRad((float)i*NA_M_LOOKUP_UNIT));
			cosLookup[(int)i] = (float) cosf(degToRad((float)i*NA_M_LOOKUP_UNIT));
			tanLookup[(int)i] = (float) tanf(degToRad((float)i*NA_M_LOOKUP_UNIT));
		}
		if(debug) cout<<"Filled lookup\n";
	}
}

float NA_MathsLib::degToRad(float d)
{
	return (PI*d)/180;
}
float NA_MathsLib::radToDeg(float r)
{
	return (r*180)/PI;
}

int NA_MathsLib::degToLookupIndex(float d)
{
	return (int) d*(NA_M_LOOKUP_UNIT);
}

float NA_MathsLib::sin(float d)
{
	if(NA_USE_OTHER_TRIG)
	{
		return sinf(degToRad(d));
	}
	else
	{
		return sinLookup[degToLookupIndex(d)];
	}
}
float NA_MathsLib::cos(float d)
{
	if(NA_USE_OTHER_TRIG)
	{
		return cosf(degToRad(d));
	}
	else
	{
		return cosLookup[degToLookupIndex(d)];
	}
}
float NA_MathsLib::tan(float d)
{
	if(NA_USE_OTHER_TRIG)
	{
		return tanf(degToRad(d));
	}
	else
	{
    return tanLookup[degToLookupIndex(d)];
	}
}


NA_Matrix* NA_MathsLib::getIDMatrix()
{
	NA_Matrix* temp = new NA_Matrix;
	return temp;
}

NA_Matrix* NA_MathsLib::getTranslateMatrix(NA_Vector* v)
{
	NA_Matrix* temp = new NA_Matrix;
	temp->matrix[0][3] = v->x;
	temp->matrix[1][3] = v->y;
	temp->matrix[2][3] = v->z;
	return temp;
}

NA_Matrix* NA_MathsLib::getTranslateMatrix(float x, float y, float z)
{
	NA_Vector* tempV = new NA_Vector (x,y,z,1.0f);
	NA_Matrix* tempM;
	tempM = this->getTranslateMatrix(tempV);
	delete tempV; //delete temp vector
	return tempM; //return temp matrix
}

NA_Matrix* NA_MathsLib::getScaleMatrix(float s)
{
	NA_Matrix* temp = new NA_Matrix;
	/*old method - very bad for optimisation
	for(int i = 0; i<3;i++)
	{
		temp->set(i,i,s);
	}
	*/
	temp->matrix[3][3] = 1/s;//new method, same effect in one line without a loop
	return temp;
}

NA_Matrix* NA_MathsLib::getRotateXMatrix(float d)
{
	NA_Matrix* temp = new NA_Matrix;
	float cosD = cos(d);
	float sinD = sin(d);
	temp->matrix[1][1] = cosD;
	temp->matrix[2][2] = cosD;
	temp->matrix[1][2] = -sinD;
	temp->matrix[2][1] = sinD;
	return temp;
}

NA_Matrix* NA_MathsLib::getRotateYMatrix(float d)
{
	NA_Matrix* temp = new NA_Matrix;
	float cosD = cos(d);
	float sinD = sin(d);
	temp->matrix[0][0] = cosD;
	temp->matrix[2][2] = cosD;
	temp->matrix[0][2] = sinD;
	temp->matrix[2][0] = -sinD;
	return temp;
}

NA_Matrix* NA_MathsLib::getRotateZMatrix(float d)
{
	NA_Matrix* temp = new NA_Matrix;
	float cosD = cos(d);
	float sinD = sin(d);
	temp->matrix[0][0] = cosD;
	temp->matrix[1][1] = cosD;
	temp->matrix[1][0] = sinD;
	temp->matrix[0][1] = -sinD;
	return temp;
}
	
NA_Matrix* NA_MathsLib::getShearXMatrix(float s)
{
	NA_Matrix* temp = new NA_Matrix;
	temp->matrix[0][0] = s;
	return temp;
}

NA_Matrix* NA_MathsLib::getShearYMatrix(float s)
{
	NA_Matrix* temp = new NA_Matrix;
	temp->matrix[1][1] = s;
	return temp;
}

NA_Matrix* NA_MathsLib::getShearZMatrix(float s)
{
	NA_Matrix* temp = new NA_Matrix;
	temp->matrix[2][2] = s;
	return temp;
}
