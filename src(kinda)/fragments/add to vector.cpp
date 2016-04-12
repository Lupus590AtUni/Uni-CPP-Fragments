NA_Vector* rotateVector(NA_Vector* v,float a)
{
	NA_Matrix* m= maths.getRotateZMatrix(a); //i hope this is the correct matrix
	return m->matrixXvector(v);
}

