#include <iostream>
const double EPSILON = 0.0000000001;

double Abs(double num)
{
    if (num - EPSILON < 0) 
    {
        return  -num;
    }
    return num;
}

bool checkSquare(double x1, double y1, double x2, double y2)
{
    if (x1 == y2 && x2 == y2)
    {
        return true;
    }
    if (Abs(x1 - x2) ==  Abs(y1 - y2))
    {
        return true;
    }
    return false;
}

int main()
{
    std::cout << checkSquare(-4, -3, 1, -2);
}
