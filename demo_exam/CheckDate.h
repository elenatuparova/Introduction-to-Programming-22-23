#pragma once

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
	int index = 0;
	int len = getLen(array);
	if (len != 5)
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

	int days = (array[index] - '0') * 10 + (array[index + 1] - '0');
	int	month = (array[index+3] - '0') * 10 + (array[index+4] - '0');

	if (days < 1 || days > 31 || month > 12 )
	{
		return false;
	}
	if (month == 2 && days > 29)
	{
		return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && days > 30)
	{
		return false;
	}
	return true;
	
}