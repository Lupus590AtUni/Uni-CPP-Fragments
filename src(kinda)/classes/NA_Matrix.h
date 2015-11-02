#pragma once
#include "NA_GlobalsAndIncludes.h"
class NA_Matrix
{
private:
  static const bool DEBUG = false;
  
public:

	float matrix[4][4];//was private but gets and sets slow things down

  NA_Matrix(NA_Matrix m);
	NA_Matrix(void);
	~NA_Matrix(void);

	void correctW();
	NA_Matrix transpose();//inverse
	NA_Matrix matrixXmatrix(NA_Matrix);//TODO make operand version
};