#include <iostream>



bool IsFirstGreaterThanSecond(int num1, int num2)
{
	int lastDigitNum1 = num1 % 10;
	int lastDigitNum2 = num2 % 10;
	if (lastDigitNum1 > lastDigitNum2)
	{
		return true;
	}
	if (lastDigitNum1 == lastDigitNum2)
	{
		return num1 > num2;
	}
	return false;
}

int Abs(int a)
{
	return a < 0 ? -a : a;
}

bool IsFirstGreaterThanSecondAbs(int num1, int num2)
{
	num1 = Abs(num1);
	num2 = Abs(num2);

	if (num1>num2)
	{
		return true;
	}
	return false;
}

void Swap(int& a, int& b)
{
	a += b;
	b = a - b;
	a -= b;
}

void Sort(int* arr, int size, bool(*funcPtr) (int, int))
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			int result = funcPtr(arr[i], arr[j]);
			if (result == true)
			{
				Swap(arr[i], arr[j]);
			}
		}
	}
}
int main()
{
	int sizeArray = 0;
	std::cin >> sizeArray;

	int* arr = new int[sizeArray];
	for (int i = 0; i < sizeArray; i++)
	{
		std::cin >> arr[i];
	}
	//ex1
	Sort(arr, sizeArray, IsFirstGreaterThanSecond);

	//ex2
	//Sort(arr, sizeArray, IsFirstGreaterThanSecondAbs);

	for (int i = 0; i < sizeArray; i++)
	{
		std::cout << arr[i] << " ";
	}

}