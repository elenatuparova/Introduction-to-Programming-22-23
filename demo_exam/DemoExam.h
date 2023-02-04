#pragma once
const char LOWER_BOUND = '0';
const char UPPER_BOUND = '9';
const char POINT = '.';
const int JANUARY = 1;
const int FEBRUARY = 2;
const int MARCH = 3;
const int APRIL = 4;
const int MAY = 5;
const int JUNE = 6;
const int JULY = 7;
const int AUGUST = 8;
const int SEPTEMBER = 9;
const int OCTOBER = 10;
const int NOVEMBER = 11;
const int DECEMBER = 12;
const char TO_DIGIT = '0';
const double  EPSILON = 0.000001;

int getStrLen(const char* str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return len;
}

bool isDigit(char num)
{
	return num >= LOWER_BOUND && num <= UPPER_BOUND;
}
bool CheckDate(char str[])
{
	if (!(str != nullptr
		&& isDigit(str[0])
		&& isDigit(str[1])
		&& isDigit(str[3])
		&& isDigit(str[4])
		&& str[2] == POINT
		&& getStrLen(str) == 5))
	{
		return false;
	}
	int day = (str[0] - TO_DIGIT) * 10 + str[1] - TO_DIGIT;
	int month = (str[3] - TO_DIGIT) * 10 + str[4] - TO_DIGIT;

	if (day < 1)
	{
		return false;
	}
	if (month > 12 || month < 1)
	{
		return false;
	}
	if (month == FEBRUARY)
	{
		return (day <= 29);
	}
	if (month == JANUARY
		|| month == MARCH
		|| month == MAY
		|| month == JULY
		|| month == AUGUST
		|| month == OCTOBER
		|| month == DECEMBER)
	{
		return day <= 31;
	}
	return day <= 30;
}

double abs(double n)
{
	return n < 0 ? -n : n;
}

bool areEqualsDoubles(double a, double b)
{
	return abs(a - b) <= EPSILON;
}

bool checkSquare(double x1, double y1, double x2, double y2)
{
	return areEqualsDoubles(abs(x1 - x2), abs(y1 - y2));
}

int getNumLen(int num)
{
	if (num == 0)
	{
		return 0;
	}
	return getNumLen(num / 10) + 1;
}

int digitPos(long num, int k)
{
	if (num == 0 && k == 1)
	{
		return 0;
	}
	int len = getNumLen(num);
	int toRemove = len - k;
	if (k > len)
	{
		return -1;
	}
	for (size_t i = 0; i < toRemove; i++)
	{
		num /= 10;
	}
	return num % 10;
}


