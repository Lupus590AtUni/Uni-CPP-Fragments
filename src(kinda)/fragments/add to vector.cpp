NA_Vector* rotateVector(NA_Vector* v,float a)
{
	NA_Matrix* m= maths.getRotateZMatrix(a); //i hope this is the correct matrix
	return m->matrixXvector(v);
}

NA_Vector* twoPointsIntoVector(NA_Vector* startPoint, NA_Vector* endPoint)
{
	NA_Vector* v = new NA_Vector;
	v->x = (endPoint->x - startPoint->x);
	v->y = (endPoint->y - startPoint->y);
	v->z = (endPoint->z - startPoint->z);
	v->w = (endPoint->w - startPoint->w);
	return v;
}