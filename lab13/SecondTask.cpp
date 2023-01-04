#include <iostream>

int absolteValue(int a)
{
	return a < 0 ? -a : a;
}
void swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

bool sortByAbsoluteValueDescendingPredicate(int a, int b)
{
	return absolteValue(a) == absolteValue(b) ? a > b : absolteValue(a) > absolteValue(b);
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
	int arr[] = { 4,8,-13,13,-10 };
	sort(arr, 5, sortByAbsoluteValueDescendingPredicate);
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}

	return 0;
}
