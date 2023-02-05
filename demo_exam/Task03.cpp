#include <iostream>

int GetNumLength(long number)
{
	int count = 0;
	if (number == 0)
	{
		return 1;
	}
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return count;
}

int GetDigitAtIndex(long num, int index, int numLength)
{
	for (int i = 0; i < numLength - index; i++)
	{
		num /= 10;
	}
	return num % 10;
}

int DigitPos(long num, int k)
{
	int numLength = GetNumLength(num);
	if (numLength < k)
	{
		return -1;
	}
	return GetDigitAtIndex(num, k, numLength);
}

int main()
{
	//task 03
	long number;
	int position;
	std::cin >> number;
	std::cin >> position;
	std::cout << DigitPos(number, position);
}