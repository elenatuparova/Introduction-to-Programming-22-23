#pragma once

int getLenOfNum(long num)
{
	int counter = 0;
	while (num != 0)
	{
		counter++;
		num /= 10;
	}
	return counter;
}

long Reverse(long num)
{
	long resultReversed = 0;
	int lastDigit = 0;
	while (num != 0)
	{
		lastDigit = num % 10;
		(resultReversed *= 10) += lastDigit;
		num /= 10;
	}
	return resultReversed;
}

int DigitPos(long num, int k)
{
	int counter = 1;
	int len = getLenOfNum(num);
	if (len < k)
	{
		return -1;
	}
	long reversedNum = Reverse(num);
	while (counter != k)
	{
		reversedNum /= 10;
		counter++;
	}
	int digit = reversedNum % 10;
	return digit;
}