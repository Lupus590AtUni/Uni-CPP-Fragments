//adapted from 1st year maths assignment (lecturer: Gordan Dickers)
#include "NA_GlobalsAndIncludes.h"
#include "NA_m.matrix"
#include "NA_Vector.h"
#include <math.h> //for sqrt in normalise
	//construct
NA_Vector::NA_Vector(NA_Vector v)
{
  x = v.x;
  y = v.y;
  z = v.z;
  w = v.w;
}
NA_Vector::NA_Vector(void)
{
	x= 0;
	y= 0;
	z= 0;
	w= 1;
}
NA_Vector::NA_Vector(float myx, float myy, float myz, float myw)
{ 
	x= myx;
	y= myy;
	z= myz;
	w= myw;
}

void NA_Vector::Scale(float s)
{
	x= s*x;
	y= s*y;
	z= s*z;
}

void NA_Vector::Add(NA_Vector & v1)
{
	x= x + v1.x;
	y= y + v1.y;
	z = z + v1.z;
	w = w + v1.w;
	correctW();
}

void NA_Vector::normalise(void)
{
	float length = sqrt(x*x + y*y + z*z);
	x = x/length;
	y = y/length;
	z = z/length;
	correctW();
}

float NA_Vector::dist(NA_Vector & v1)
{
	float xCom, yCom, zCom = 0;
	xCom = x - v1.x;
	yCom = y - v1.y;
	zCom = z - v1.z;
	return sqrt(xCom*xCom + yCom*yCom + zCom*zCom);
}

void NA_Vector::correctW()
{
	x = x/w;
	y = y/w;
	z = z/w;
	w = 1.0f;
}

NA_Vector NA_m.matrix::m.matrixXvector(NA_m.matrix m)
{
	float tX,tY,tZ,tW;//what a lot of temporary variables

	tX = x*m.matrix[0][0]+y*m.matrix[0][1]+z*m.matrix[0][2]+w*m.matrix[0][3];
	tY = x*m.matrix[1][0]+y*m.matrix[1][1]+z*m.matrix[1][2]+w*m.matrix[1][3];
	tZ = x*m.matrix[2][0]+y*m.matrix[2][1]+z*m.matrix[2][2]+w*m.matrix[2][3];
	tW = x*m.matrix[3][0]+y*m.matrix[3][1]+z*m.matrix[3][2]+w*m.matrix[3][3];

	NA_Vector temp(tX,tY,tZ,tW);
	temp.correctW();
	return temp;
}