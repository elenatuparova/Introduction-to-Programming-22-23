#pragma once

bool CheckDate(char input[])
{
	int i = 0;
	while (input[i] != '\0')
	{
		i++;
	}
	if (i > 5)
	{
		return false;
	}
	if ((input[0] < '0' || input[0] > '3') || (input[1] < '0' || input[1] > '9'))
	{
		return false;
	}
	int day = (input[0] - '0') * 10 + (input[1] - '0');
	if (day < 1 || day > 31)
	{
		return false;
	}
	if (input[2] != '.')
	{
		return false;
	}
	if ((input[3] < '0' || input[3] > '1') || (input[0] < '0' || input[1] > '9'))
	{
		return false;
	}
	int month = (input[3] - '0') * 10 + (input[4] - '0');
	if (month < 1 || month > 12)
	{
		return false;
	}
	switch (month)
	{
	case 4:
	case 6:
	case 9:
	case 11: if (day > 30) return false;
		break;
	case 2: if (day > 28) return false;
		break;
	default:
		break;
	}
	return true;
}

bool CheckSquare(double x1, double y1, double x2, double y2)
{
	double epsilon = 0.00001;
	double diffY = y2 > y1 ? y2 - y1 : y1 - y2;
	double diffX = x2 > x1 ? x2 - x1 : x1 - x2;
	return diffY + epsilon == diffX ||
		diffY - epsilon == diffX ||
		diffY == diffX;
}

int DigitPos(long num, int k)
{
	int lenght = 0;
	long tempNum = num;
	while (tempNum != 0)
	{
		tempNum /= 10;
		lenght++;
	}
	if (lenght < k)
	{
		return -1;
	}
	tempNum = num;
	long reversedNum = 0;
	while (tempNum != 0)
	{
		reversedNum *= 10;
		reversedNum += tempNum % 10;
		tempNum /= 10;
	}
	int i = 1;
	while (i < k)
	{
		reversedNum /= 10;
		i++;
	}
	return reversedNum % 10;
}
