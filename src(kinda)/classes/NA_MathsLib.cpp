#include "NA_MathsLib.h"
#include <math.h>//used to generate lookup tables when object is constructed
#include "NA_Vector.h"
#include "NA_Matrix.h"
#include "stdafx.h"
#include <random>
#include <time.h>

const float NA_MathsLib::PI = 3.14f;//this is a stupid compiler rule in my opinion

NA_MathsLib maths; //contructs itself, access with extern NA_MathsLib maths;

NA_MathsLib::NA_MathsLib(void)
{
  debug = false;
  if(!NA_USE_OTHER_TRIG)
	{
		for(int i=0; i<NA_M_LOOKUP_MAX; i++)//walk through lookup table assigning values from math.h
		{
			sinLookup[(int)i] = (float) sinf(degToRad((float)i*NA_M_LOOKUP_UNIT));
			cosLookup[(int)i] = (float) cosf(degToRad((float)i*NA_M_LOOKUP_UNIT));
			tanLookup[(int)i] = (float) tanf(degToRad((float)i*NA_M_LOOKUP_UNIT));
		}
	}
}

NA_MathsLib::~NA_MathsLib(void)
{
}

#pragma region dice

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

#pragma endregion

#pragma region trig

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

#pragma endregion

#pragma region matrix

NA_Matrix NA_MathsLib::getIDMatrix()
{
	NA_Matrix temp;
	return temp;
}

NA_Matrix NA_MathsLib::getTranslateMatrix(NA_Vector v)
{
	NA_Matrix temp;
	temp.matrix[0][3] = v.x;
	temp.matrix[1][3] = v.y;
	temp.matrix[2][3] = v.z;
	return temp;
}

NA_Matrix NA_MathsLib::getTranslateMatrix(float x, float y, float z)
{
	NA_Vector tempV(x,y,z,1.0f);
	NA_Matrix tempM;
	tempM = getTranslateMatrix(tempV);
	return tempM; //return temp matrix
}

NA_Matrix NA_MathsLib::getScaleMatrix(float s)
{
	NA_Matrix temp;
	temp.matrix[3][3] = 1/s;
	return temp;
}

NA_Matrix NA_MathsLib::getRotateXMatrix(float d)
{
	NA_Matrix temp;
	float cosD = cos(d);
	float sinD = sin(d);
	temp.matrix[1][1] = cosD;
	temp.matrix[2][2] = cosD;
	temp.matrix[1][2] = -sinD;
	temp.matrix[2][1] = sinD;
	return temp;
}

NA_Matrix NA_MathsLib::getRotateYMatrix(float d)
{
	NA_Matrix temp;
	float cosD = cos(d);
	float sinD = sin(d);
	temp.matrix[0][0] = cosD;
	temp.matrix[2][2] = cosD;
	temp.matrix[0][2] = sinD;
	temp.matrix[2][0] = -sinD;
	return temp;
}

NA_Matrix NA_MathsLib::getRotateZMatrix(float d)
{
	NA_Matrix temp;
	float cosD = cos(d);
	float sinD = sin(d);
	temp.matrix[0][0] = cosD;
	temp.matrix[1][1] = cosD;
	temp.matrix[1][0] = sinD;
	temp.matrix[0][1] = -sinD;
	return temp;
}
	
NA_Matrix NA_MathsLib::getShearXMatrix(float s)
{
	NA_Matrix temp;
	temp.matrix[0][0] = s;
	return temp;
}

NA_Matrix NA_MathsLib::getShearYMatrix(float s)
{
	NA_Matrix temp;
	temp.matrix[1][1] = s;
	return temp;
}

NA_Matrix NA_MathsLib::getShearZMatrix(float s)
{
	NA_Matrix temp;
	temp.matrix[2][2] = s;
	return temp;
}

#pragma endregion


//returns true if the two floats are within 0.001 of each other
bool aboutEqual(float v1, float v2, float epsilon = 0.001f)
{
	if (v1 > v2)
	{
		if( v1 - v2 < epsilon) return true;
	}
	else
	{
		if( v2 - v1 < epsilon) return true; //this returns true if they are exactly equal too, therefore a if(v1 == v2) statement is not required
	}
	return false; //if this line is executed then the two values are not similar enough to be considered the same
}