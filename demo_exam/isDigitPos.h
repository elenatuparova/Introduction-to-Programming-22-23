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

int DigitPos(long num, int k)
{
	int counter = 1;
	int len = getLenOfNum(num);
	if (len < k)
	{
		return -1;
	}
	if (num == 0 && k == 1)
	{
		return 0;
	}
	int remove = len - k;
	while (remove)
	{
		num /= 10;
		remove--;
	}
	int digit = num % 10;
	return digit;
}