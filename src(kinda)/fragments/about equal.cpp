//returns true if the two floats are within 0.001 of each other
bool aboutEqual(float v1, float v2)
{
	const float EPSILON = 0.001f;
	if (v1 > v2)
	{
		if( v1 - v2 < EPSILON) return true;
	}
	else
	{
		if( v2 - v1 < EPSILON) return true; //this returns true if they are exactly equal too, therefore a if(v1 == v2) statement is not required
	}
	return false; //if this line is executed then the two values are not similar enough to be considered the same
}

//same but custom epsilon
bool aboutEqual(float v1, float v2, float epsilon)
{
	if (v1 > v2)
	{
		if( v1 - v2 < epsilon) return true;
	}
	else
	{
		if( v2 - v1 < epsilon) return true; //this returns true if they are exactly equal too, therefore a if(v1 == v2) statement is not required
	}
	return false; //if this line is executed then the two values are not similar enough to be considered the same
}