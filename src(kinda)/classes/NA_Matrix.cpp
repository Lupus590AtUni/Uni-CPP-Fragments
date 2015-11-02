#include "NA_GlobalsAndIncludes.h"
#include "NA_Matrix.h"

NA_Matrix::NA_Matrix(NA_Matrix m)
{
	for(int i = 0; i<4;i++)
	{
		for(int j = 0;j<4;j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
}
NA_Matrix::NA_Matrix(void)
{
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

NA_Matrix NA_Matrix::transpose()
{
	NA_Matrix temp;
	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			temp.matrix[i][j] = matrix[j][i];
		}
	}
	return temp;
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

void NA_Matrix::correctW()
{
	for(int i = 0; i<4;i++)
	{
		for(int j = 0; j<4;j++)
		{
			matrix[i][j] = matrix[i][j]/matrix[3][3];
		}
	}
	
	//matrix[3][3] = 1.0f;//I do this in the loop already
}