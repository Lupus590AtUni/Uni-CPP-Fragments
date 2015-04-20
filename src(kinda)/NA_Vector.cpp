//adapted from 1st year maths assignment (lecturer: Gordan Dickers)
#include "NA_GlobalsAndIncludes.h"
#include "NA_Vector.h"
#include <math.h> //for sqrt in normalise
	//construct
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
	xCom = this->x - v1.x;
	yCom = this->y - v1.y;
	zCom = this->z - v1.z;
	return sqrt(xCom*xCom + yCom*yCom + zCom*zCom);
}

void NA_Vector::correctW()
{
	x = x/w;
	y = y/w;
	z = z/w;
	w = 1.0f;
}


#pragma region DEPRECATED
float NA_Vector::getX(void)
{
	return x;
}
float NA_Vector::getY(void)
{
	return y;
}
float NA_Vector::getZ(void)
{
	return z;
}
float NA_Vector::getW(void)
{
	return w;
}

void NA_Vector::setX(float newX)
{
	x = newX;
}
void NA_Vector::setY(float newY)
{
	y = newY;
}
void NA_Vector::setZ(float newZ)
{
	z = newZ;
}
void NA_Vector::setW(float newW)
{
	w = newW;
}
#pragma endregion DEPRECATED