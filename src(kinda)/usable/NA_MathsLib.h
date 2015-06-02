#pragma once
#include "NA_GlobalsAndIncludes.h"
class NA_Vector;
class NA_Matrix;
class NA_MathsLib
{
private:
	static const bool  NA_USE_OTHER_TRIG = false; //if true use math.h trig when own is called (don't use lookup)
	static const int NA_M_LOOKUP_MAX = 1024;
	static const int NA_M_LOOKUP_UNIT = 360/NA_M_LOOKUP_MAX;
	
	//could these be static?
	float sinLookup[(int)NA_M_LOOKUP_MAX];
	float cosLookup[(int)NA_M_LOOKUP_MAX];
	float tanLookup[(int)NA_M_LOOKUP_MAX];

	int degToLookupIndex(float);

public:
  bool debug;
	void seedDice();
	void seedDice(unsigned int seed);

	static const float PI;//floats must be initialised in cpp
	NA_MathsLib(void);
	~NA_MathsLib(void);

	//had to name dice as could not access randoms rand function if maths::rand was so named
	int dice(int bottom, int top);
	int dice(int top);

	void init();//fills the lookup tables
	float degToRad(float);
	float radToDeg(float);
	float sin(float);
	float cos(float);
	float tan(float);


	//need to rename these, get is misleading, generate/make would be better
	NA_Matrix* getIDMatrix();
	NA_Matrix* getTranslateMatrix(NA_Vector*);
	NA_Matrix* getTranslateMatrix(float,float,float);
	NA_Matrix* getScaleMatrix(float);

	NA_Matrix* getRotateXMatrix(float);
	NA_Matrix* getRotateYMatrix(float);
	NA_Matrix* getRotateZMatrix(float);
	
	NA_Matrix* getShearXMatrix(float);
	NA_Matrix* getShearYMatrix(float);
	NA_Matrix* getShearZMatrix(float);
};

