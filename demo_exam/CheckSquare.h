#pragma once


double Abs(double num)
{
	return (num > 0) ? num : -num;
}

double campareDoubles(double a, double b, double EPSILON = 0.0000001)
{
	return (Abs(a - b) < EPSILON) ? true : false;
}

bool checkSquare(double x1, double y1, double x2, double y2)
{
	if ((campareDoubles(x1, x2) && campareDoubles(y1, y2))
		|| campareDoubles(x1, x2) 
		|| campareDoubles(y1, y2))
	{
		return false;
	}
	if (campareDoubles(Abs(x1-x2),Abs(y1-y2)))
	{
		return true;
	}
	return false;
}