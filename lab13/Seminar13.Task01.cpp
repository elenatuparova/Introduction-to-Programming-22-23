#include <iostream>
//Напишете функция, която сортира масив от цели числа в намаляващ ред 
//на абсолтната им стойност

int Abs(int num)
{
	return num > 0 ? num : -num;
}

void mySwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

bool sortByAbs(int a, int b)
{
	return Abs(a) == Abs(b) ? a > b:Abs(a) > Abs(b);
}

void sortArray(int* array, bool (*isSmall) (int,int), int size)
{
	int minIndex = 0;
	for (int i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (int j = i+1; j < size; j++)
		{
			if (sortByAbs(array[j],array[minIndex]))
			{
				minIndex = j;
			}
		}
		mySwap(array[i], array[minIndex]);
	}
}

int main()
{
	int arr[] = { 2,6,-7,9,1 };
	sortArray(arr, sortByAbs, 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}

	return 0;
}