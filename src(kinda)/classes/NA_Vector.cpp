//adapted from 1st year maths assignment (lecturer: Gordan Dickers)
#include "NA_Vector.h"
#include <math.h> //for sqrt in normalise - should redo to use custom math lib which has a lookup table for this
	//construct

NA_Vector::NA_Vector(float myx=0.0f, float myy=0.0f, float myz=0.0f, float myw=0.0f)
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
  w= s*w;
}

void NA_Vector::Add(NA_Vector & v1)
{
	x= x + v1.x;
	y= y + v1.y;
	z = z + v1.z;
	w = w + v1.w;
	//correctW();
}

void NA_Vector::normalise(void)
{
	float length = sqrt(x*x + y*y + z*z);
	x = x/length;
	y = y/length;
	z = z/length;
	//correctW();
}

float NA_Vector::dist(NA_Vector & v1)
{
	float xCom, yCom, zCom = 0;
	xCom = x - v1.x;
	yCom = y - v1.y;
	zCom = z - v1.z;
	return sqrt(xCom*xCom + yCom*yCom + zCom*zCom);
}

float NA_Vector::dot(NA_Vector & v1)
{
  return x*v1.x + y*v1.y + z*v1.z + w*v1.w;
}

/*void NA_Vector::correctW()
{
	x = x/w;
	y = y/w;
	z = z/w;
	w = 1.0f;
}
*/