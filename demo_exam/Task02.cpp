#include <iostream>

const double epsilon = 0.00000000001;

double Abs(double num)
{
	return num > 0 ? num : -num;
}

bool CheckIsSquare(double x1, double y1, double x2, double y2)
{
	if (x1==x2 || y1==y2)
	{
		return false;
	}
	if (Abs((Abs(x1 - x2) - Abs(y1 - y2))) < epsilon)
	{
		return true;
	}
	return false;
}

int main()
{
	//task02
	double x1, x2, y1, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	if (CheckIsSquare(x1, y1, x2, y2))
	{
		std::cout << "square!";
	}
	else
	{
		std::cout << "not square!";
	}
}