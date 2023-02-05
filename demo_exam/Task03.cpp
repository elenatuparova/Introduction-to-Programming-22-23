#include <iostream>

int digitPos(long num, int k)
{
	int numCount = 0;
	long numCopy = num;

	while (numCopy != 0)
	{
		numCopy /= 10;
		numCount++;
	}

	if (numCount - k < 1)
	{
		return -1;
	}

	int pos = numCount;
	while (true)
	{
		int digit = num % 10;
		if (pos == k)
		{
			return digit;
		}
		num /= 10;
		pos--;
	}
}

int main()
{
	std::cout << digitPos(12345674, 15);
}

