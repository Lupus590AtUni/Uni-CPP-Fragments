#include "NA_GlobalsAndIncludes.h"
#include "NA_Matrix.h"
#include "NA_Vector.h"
#include "stdafx.h"

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





//from maths lib
#pragma region matrix
//
//NA_Matrix NA_MathsLib::getIDMatrix()
//{
//	NA_Matrix temp;
//	return temp;
//}
//
//NA_Matrix NA_MathsLib::getTranslateMatrix(NA_Vector v)
//{
//	NA_Matrix temp;
//	temp.matrix[0][3] = v.x;
//	temp.matrix[1][3] = v.y;
//	temp.matrix[2][3] = v.z;
//	return temp;
//}
//
//NA_Matrix NA_MathsLib::getTranslateMatrix(float x, float y, float z)
//{
//	NA_Vector tempV(x,y,z,1.0f);
//	NA_Matrix tempM;
//	tempM = getTranslateMatrix(tempV);
//	return tempM; //return temp matrix
//}
//
//NA_Matrix NA_MathsLib::getScaleMatrix(float s)
//{
//	NA_Matrix temp;
//	temp.matrix[3][3] = 1/s;
//	return temp;
//}
//
//NA_Matrix NA_MathsLib::getRotateXMatrix(float d)
//{
//	NA_Matrix temp;
//	float cosD = cos(d);
//	float sinD = sin(d);
//	temp.matrix[1][1] = cosD;
//	temp.matrix[2][2] = cosD;
//	temp.matrix[1][2] = -sinD;
//	temp.matrix[2][1] = sinD;
//	return temp;
//}
//
//NA_Matrix NA_MathsLib::getRotateYMatrix(float d)
//{
//	NA_Matrix temp;
//	float cosD = cos(d);
//	float sinD = sin(d);
//	temp.matrix[0][0] = cosD;
//	temp.matrix[2][2] = cosD;
//	temp.matrix[0][2] = sinD;
//	temp.matrix[2][0] = -sinD;
//	return temp;
//}
//
//NA_Matrix NA_MathsLib::getRotateZMatrix(float d)
//{
//	NA_Matrix temp;
//	float cosD = cos(d);
//	float sinD = sin(d);
//	temp.matrix[0][0] = cosD;
//	temp.matrix[1][1] = cosD;
//	temp.matrix[1][0] = sinD;
//	temp.matrix[0][1] = -sinD;
//	return temp;
//}
//	
//NA_Matrix NA_MathsLib::getShearXMatrix(float s)
//{
//	NA_Matrix temp;
//	temp.matrix[0][0] = s;
//	return temp;
//}
//
//NA_Matrix NA_MathsLib::getShearYMatrix(float s)
//{
//	NA_Matrix temp;
//	temp.matrix[1][1] = s;
//	return temp;
//}
//
//NA_Matrix NA_MathsLib::getShearZMatrix(float s)
//{
//	NA_Matrix temp;
//	temp.matrix[2][2] = s;
//	return temp;
//}
//