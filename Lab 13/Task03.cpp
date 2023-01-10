#include <iostream>

typedef int(*Abs)(int);

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int abs(int a)
{
	if (a < 0)
	{
		return a;
	}
	else return a;
}



void arraySort(int arr[], int arrSize, Abs absoluteValue)
{

	for (int i = 0; i < arrSize - 1; i++)
	{
		bool isSwapped = false;
		for (int j = 0; j < arrSize - i - 1; j++)
		{
			if (absoluteValue(arr[j]) < absoluteValue(arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		}
		if (!isSwapped) {
			return;
		}
	}
}

int main()
{
	int arrSize = 0;
	std::cin >> arrSize;

	int* arr = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		std::cin >> arr[i];
	}

	arraySort(arr, arrSize, [](int a) {return a >= 0 ? a : a; });

	for (int i = 0; i < arrSize; i++)
	{
		std::cout << arr[i] << " ";
	}
	delete[] arr;
}