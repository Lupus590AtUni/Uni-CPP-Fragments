#pragma once
#include "NA_GlobalsAndIncludes.h"
class NA_Vector;
class NA_Matrix
{
public:
  bool debug;

	float matrix[4][4];//was private but gets and sets slow things down

	NA_Matrix(void);
	~NA_Matrix(void);

	DEPRECATED(void set(int, int, float));
	DEPRECATED(float get(int, int));
	void correctW();
	NA_Matrix* matrixXmatrix(NA_Matrix*);
	NA_Vector* matrixXvector(NA_Vector*);
};
