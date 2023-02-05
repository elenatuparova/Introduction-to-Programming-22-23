#include <iostream>
const int ZERO_CODE = 48;
const int MAX_FEB_DAYS = 28;
const int MAX_BIG_DAYS = 31;
const int MAX_LESS_DAYS = 30;
const int MAX_MONTHS = 12;

bool checkDate(char date[])
{
	int day = 10 * (date[0] - ZERO_CODE) + date[1] - ZERO_CODE;
	//std::cout << day << " ";
	int month = 10 * (date[3] - ZERO_CODE) + date[4] - ZERO_CODE;
	//std::cout << month << std::endl;

	if (date[2] != '.')
	{
		return false;
	}
	if (month > MAX_MONTHS || month < 0 || day > MAX_BIG_DAYS || day < 0)
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
		if(day > MAX_LESS_DAYS)
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

int main()
{
	char date[6] = "29.02";
	std::cout << checkDate(date);
}
