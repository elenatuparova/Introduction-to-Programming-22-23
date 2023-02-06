#pragma once
const int MAX_LEN = 5;
const int MAX_DAYS = 31;
const int MAX_MONTHS = 12;
const int MIN_DAY = 1;
const int FEBRUARY = 2;
const int APRIL = 4;
const int JUNE = 6;
const int SEPTEMBER = 9;
const int NOVEMBER = 11;

int getLen(char* arr)
{
	int index = 0;
	if (arr[0] == '\0')
	{
		return 0;
	}
	while (arr[index] != 0)
	{
		index++;
	}
	return index + 1;
}

bool checkDate(char* array)
{
	int len = getLen(array);
	if (len != MAX_LEN)
	{
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if ((array[i] < '0' && array[i]>'9') && array[2]!='.')
		{
			return false;
		}
	}

	int days = (array[0] - '0') * 10 + (array[1] - '0');
	int	month = (array[3] - '0') * 10 + (array[4] - '0');

	if (days < MIN_DAY || days > MAX_DAYS || month > MAX_MONTHS )
	{
		return false;
	}
	if (month == FEBRUARY && days > (MAX_DAYS-2))
	{
		return false;
	}
	if ((month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER) && days > (MAX_DAYS-1))
	{
		return false;
	}
	return true;
	
}