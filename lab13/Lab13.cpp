#include <iostream>

bool CompareLastDigit(int num1, int num2)
{
	if (num1 % 10 > num2 % 10)
	{
		return true;
	}
	else if (num1 % 10 < num2 % 10)
	{
		return false;
	}

	return num1 > num2;
}

void Swap(int& num1, int& num2)
{
	int helper = num1;
	num1 = num2;
	num2 = helper;;
}

void Sort(int* numbers, int length, bool (*compare) (int, int))
{
	for (size_t i = 0; i < length - 1; i++)
	{
		bool areSwapped = false;
		for (size_t j = 0; j < length - 1; j++)
		{
			if (compare(numbers[j], numbers[j + 1]))
			{
				areSwapped = true;
				Swap(numbers[j], numbers[j + 1]);
			}
		}
		if (!areSwapped)
		{
			break;
		}
	}
}

int Abs(int num)
{
	return num < 0 ? -num : num;
}

int main()
{
	int arr[] = { -95, -13, -8, -123, -4567 };

	bool (*compareLastDigit) (int, int) = CompareLastDigit;
	Sort(arr, 5, compareLastDigit);
	Sort(arr, 5, [](int n1, int n2) {return Abs(n1) < Abs(n2); });

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}
}
