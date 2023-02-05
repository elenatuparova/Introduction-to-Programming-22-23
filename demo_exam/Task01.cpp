#include <iostream>

const int lengthDate = 5;

bool CheckIsDayValid(int day, int month)
{
	if (month == 7 && day >= 1 && day <= 31)
	{
		return true;
	}
	if (month == 2 && day >= 1 && day <= 29)
	{
		return true;
	}
	if (month % 2 == 0 && day >= 1 && day <= 30 && month != 2)
	{
		return true;
	}
	if (month % 2 == 1 && day >= 1 && day <= 31)
	{
		return true;
	}
	return false;
}

bool CheckValidSymbols(char* date)
{
	for (int i = 0; i < lengthDate; i++)
	{
		if (i == 2 && date[i] != '.')
		{
			return false;
		}
		if ((date[i] < '0' || date[i] > '9') && i != 2)
		{
			return false;
		}
	}
	return true;
}

bool CheckDate(char* inputDate)
{
	if (CheckValidSymbols(inputDate))
	{
		int day = (inputDate[0] - '0') * 10 + (inputDate[1] - '0');
		int month = (inputDate[3] - '0') * 10 + (inputDate[4] - '0');
		if (month >= 1 && month <= 12)
		{
			if (day >= 28 || day <= 31)
			{
				if (CheckIsDayValid(day, month))
				{
					return true;
				}
			}
		}
	}
	return false;
}



int main()
{
	//task01
	char* date = new char[lengthDate];
	int i = 0;
	for (; i < lengthDate; i++)
	{
		std::cin >> date[i];
	}
	date[i] = '\0';
	if (CheckDate(date))
	{
		std::cout << "Correct";
	}
	else
	{
		std::cout << "incorrect";
	}
	//that delete makes error?!?
	//delete[] date;
}