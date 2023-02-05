#pragma once

int countSymbols(char myChar[])
{
	int index = 0;
	int counter = 0;
	while (myChar[index] != '\0')
	{
		counter++;
		index++;
	}
	return counter;
}

bool CheckDate(char date[])
{
	if (countSymbols(date) != 5)
	{
		return false;
	}
	if (date[2] != '.')
	{
		return false;
	}
	int myDate = (date[0] - '0') * 10 + date[1] - '0';
	int month = (date[3] - '0') * 10 + date[4] - '0';
	
	if (month >= 1 && month <= 12 && myDate >= 1 && myDate <= 31)
	{
		if (month % 2 == 1 && month <= 7 && month != 2)
		{
			return true;
		}
		else if (month == 2)
		{
			if (myDate >= 1 && myDate <= 28)
			{
				return true;
			}
		}
		else if (month % 2 == 0 && month < 7 && month != 2)
		{
			if (myDate >= 1 && myDate <= 30)
			{
				return true;
			}
		}
		else if (month % 2 == 0 && month >= 8)
		{
			if (myDate >= 1 && myDate <= 31)
			{
				return true;
			}
		}
		else if (month % 2 == 1 && month > 8)
		{
			if(myDate>=1 && myDate <=30)
			{
				return true;
			}
		}
		else { return false; }
	}
	else { return false; }
	
}

// Task2
double const EPSILON = 0.000001;
double powNumber(double number, int power)
{
	double result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= number;
	}
	return result;
}

bool CheckSquare(double x1, double y1, double x2, double y2)
{
	double x3 = x1;
	double y3 = y2;
	double distance1 = powNumber(x3 - x1, 2) + powNumber(y3 - y1, 2);
	double distance2 = powNumber(x3 - x2, 2) + powNumber(y3 - y2, 2);
	double difference = distance1 - distance2;
	double absDifference = difference > 0 ? difference : -difference;
	if (absDifference < EPSILON)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Task3

long powNumber1(long num, int power)
{
	long result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= num;
	}
	return result;
}

int countDigits(long num)
{
	int counter = 0;
	while (num != 0)
	{
		num /= 10;
		counter++;
	}
	return counter;
}

int DigitPos(long num, int k)
{
	if (k > countDigits(num))
	{
		return -1;
	}
	int power = countDigits(num);
	int result = 0;
	for (int i = 1; i <= k; i++)
	{
		result = num / powNumber1(10, power - i);
		num = num % powNumber1(10, power - i);
	}
	return result;
}
