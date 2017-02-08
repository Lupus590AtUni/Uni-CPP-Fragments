//adapted from 1st year maths assignment (lecturer: Gordan Dickers)
#pragma once

class NA_Vector
{
public:

	//construct
	NA_Vector(float x=0.0f, float y=0.0f, float z=0.0f, float w=0.0f);
	NA_Vector(const NA_Vector &copy);
	NA_Vector(NA_Vector *const copy);
	void scale(float s);
	void add(NA_Vector & v1);
	void normalise(void);
	float dist(NA_Vector & v1);
	float dot(NA_Vector & v1);
	float length();
	static NA_Vector twoPointsIntoVector(NA_Vector & startPoint, NA_Vector & endPoint);
	float clockwiseAngle(NA_Vector & v1);

	NA_Vector operator-(NA_Vector);
	NA_Vector operator+(NA_Vector);

	static NA_Vector normalise(NA_Vector);
	static NA_Vector cross(NA_Vector, NA_Vector);
	static float dot(NA_Vector, NA_Vector);

	//were private, but gets and sets slowdown realtime systems (such as games)
	float x;
	float y;
	float z;
	float w;
};