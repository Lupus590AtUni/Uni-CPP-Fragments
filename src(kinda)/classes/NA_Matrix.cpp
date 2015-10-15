#include "NA_GlobalsAndIncludes.h"
#include "NA_Matrix.h"
#include "NA_Vector.h"

NA_Matrix::NA_Matrix(void)
{
  debug = false;
	//make identity matrix
	for(int i = 0; i<4;i++)
	{
		for(int j = 0;j<4;j++)
		{
			if(i==j)
			{
				matrix[i][j] = 1.0f;
			}
			else
			{
				matrix[i][j] = 0.0f;
			}
		}
	}
}
NA_Matrix::~NA_Matrix(void)
{
}



NA_Matrix NA_Matrix::matrixXmatrix(NA_Matrix m)
{
	NA_Matrix temp;
	for(int i = 0; i<4;i++)
	{
		for(int j = 0; j<4;j++)
		{
			float t;
			t = m.matrix[j][i]*matrix[i][j]+m.matrix[j][i]*matrix[i][j]+m.matrix[j][i]+matrix[i][j]+m.matrix[j][i]+matrix[i][j];
			temp.matrix[i][j] = t;
		}
	}
	temp.correctW();
	return temp;
}

NA_Vector NA_Matrix::matrixXvector(NA_Vector v)
{
	float tX,tY,tZ,tW;//what a lot of temporary variables

	tX = v.x*matrix[0][0]+v.y*matrix[0][1]+v.z*matrix[0][2]+v.w*matrix[0][3];
	tY = v.x*matrix[1][0]+v.y*matrix[1][1]+v.z*matrix[1][2]+v.w*matrix[1][3];
	tZ = v.x*matrix[2][0]+v.y*matrix[2][1]+v.z*matrix[2][2]+v.w*matrix[2][3];
	tW = v.x*matrix[3][0]+v.y*matrix[3][1]+v.z*matrix[3][2]+v.w*matrix[3][3];

	NA_Vector temp(tX,tY,tZ,tW);
	temp.correctW();
	return temp;
}

void NA_Matrix::correctW()
{
	for(int i = 0; i<4;i++)
	{
		for(int j = 0; j<4;j++)
		{
			matrix[i][j] = matrix[i][j]/matrix[3][3];
		}
	}
	
	matrix[3][3] = 1.0f;
}