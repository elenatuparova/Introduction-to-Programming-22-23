#include <iostream>
//Напишете функция, която сортира масив от цели числа в
//нарастващ ред на последната им цифра.Ако две числа
//имат една и съща последна цифра, по - малкото по стойност
//да бъде преди по - голямото.

void mySwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

bool isLastDigitBigger(int a, int b)
{
	int lastDigitOfA = a % 10;
	int lastDigitOfB = b % 10;
	return lastDigitOfA == lastDigitOfB ? a < b : lastDigitOfA < lastDigitOfB;
}

void sortArray(int* array, bool (isBigger)(int, int), int size)
{
	int minIndex = 0;
	for (int i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (int j = i+1; j < size; j++)
		{
			if (isBigger(array[j], array[minIndex]))
			{
				minIndex = j;
			}
		}
		mySwap(array[i], array[minIndex]);
	}
}
int main()
{
	int arr[] = { 95,8,13,123,4567 };
	sortArray(arr, isLastDigitBigger, 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}
	return 0;
}