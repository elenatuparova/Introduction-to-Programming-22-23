#pragma once
//task 1
const int ZERO_CODE = 48;
const int MAX_FEB_DAYS = 29;
const int MAX_BIG_DAYS = 31;
const int MAX_LESS_DAYS = 30;
const int MAX_MONTHS = 12;

bool checkDate(char date[])
{
	if (date[5] != '\0')
	{
		return false;
	}
	int day = 10 * (date[0] - ZERO_CODE) + date[1] - ZERO_CODE;
	//std::cout << day << " ";
	int month = 10 * (date[3] - ZERO_CODE) + date[4] - ZERO_CODE;
	//std::cout << month << std::endl;

	if (date[2] != '.')
	{
		return false;
	}
	if (month > MAX_MONTHS || month < 1 || day > MAX_BIG_DAYS || day < 1)
	{
		return false;
	}
	if (month == 2)
	{
		if (day > MAX_FEB_DAYS)
		{
			return false;
		}
	}
	if (month % 2 == 0 && month < 7)
	{
		if (day > MAX_LESS_DAYS)
		{
			return false;
		}
	}
	if (month % 2 == 1 && month > 7)
	{
		if (day > MAX_LESS_DAYS)
		{
			return false;
		}
	}

	return true;
}

//task 2
const double EPSILON = 0.0000000001;

double Abs(double num)
{
	if (num - EPSILON < 0)
	{
		return  -num;
	}
	return num;
}

bool AreEqual(double num1, double num2)
{
	if (num1 - num2 <= EPSILON)
	{
		return true;
	}
	return false;
}

bool checkIfPointsAreSqureDiagonal(double x1, double y1, double x2, double y2)
{
	if (x1 == y2 && x2 == y2)
	{
		return true;
	}
	if (AreEqual(Abs(x1 - x2), Abs(y1 - y2)))
	{
		return true;
	}
	return false;
}

//task 3

int digitsCount(long number)
{
	int numCount = 0;

	while (number != 0)
	{
		number /= 10;
		numCount++;
	}

	return numCount;
}

int digitPos(long num, int k)
{
	int numCount = digitsCount(num);

	if (numCount - k < 0 || k <= 0)
	{
		return -1;
	}

	int pos = numCount;
	while (true)
	{
		int digit = num % 10;
		if (pos == k)
		{
			return digit;
		}
		num /= 10;
		pos--;
	}
}
