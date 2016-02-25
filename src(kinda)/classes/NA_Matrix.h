#pragma once
#include "NA_GlobalsAndIncludes.h"
class NA_Vector;
class NA_Matrix
{
public:

	float matrix[4][4];//was private but gets and sets slow things down

	NA_Matrix(void);
	~NA_Matrix(void);

	void correctW();
	NA_Matrix transpose();//inverse
	NA_Matrix matrixXmatrix(NA_Matrix);//TODO make operand version
	NA_Vector matrixXvector(NA_Vector);//TODO make operand version
};

