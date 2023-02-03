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
	if (len != 6)
	{
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if ((array[i] < '0' && array[i]>'9') || array[2]!='.')
		{
			return false;
		}
	}

	int days = (array[index] - '0') * 10 + (array[index + 1] - '0');
	int	month = (array[index+3] - '0') * 10 + (array[index+4] - '0');

	if (days <= 0 || month > 12)
	{
		return false;
	}
	if (month == 2 && month > 28)
	{
		return false;
	}
	if ((month % 2 == 0 && days > 30) || days > 31)
	{
		return false;
	}
	return true;
	
}