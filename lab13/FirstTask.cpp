#include <iostream>

void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

bool sortByLastDigitPredicate(int a, int b)
{
	return a % 10 == b % 10 ? a < b : a % 10 < b % 10;
}

void sort(int* arr, int len, bool(*isLess)(int, int))
{
	for (int i = 0; i < len - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < len; j++)
		{
			if (isLess(arr[j], arr[minIndex]))
			{
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}


int main()
{
	int arr[] = { 95,8,13,123,4567 };
	sort(arr, 5, sortByLastDigitPredicate);
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i]<<" ";
	}

	return 0;
}
