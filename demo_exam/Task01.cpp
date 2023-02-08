#include <iostream>

const int LENGTH_DATE = 5;

bool CheckIsDayValid(int day, int month)
{
	if (month <= 7)
	{
		if (month == 2 && day > 29)
		{
			return false;
		}
		if (month % 2 == 0 && day > 30)
		{
			return false;
		}
		if (month % 2 == 1 && day > 31)
		{
			return false;
		}
	}
	else
	{
		if (month % 2 == 0 && day > 31)
		{
			return false;
		}
		if (month % 2 == 1 && day > 30)
		{
			return false;
		}
	}
	return true;
}

bool CheckValidSymbols(char* date)
{
	if (date[LENGTH_DATE] != '\0')
	{
		return false;
	}
	for (int i = 0; i < LENGTH_DATE; i++)
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
			if (day >= 1 && day <= 31)
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
	char* date = new char[LENGTH_DATE+2];
	std::cin.getline(date, LENGTH_DATE+2);

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