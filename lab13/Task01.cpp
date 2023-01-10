#include <iostream>
using std::cin;
using std::cout;

typedef bool (*sortingCriteria)(int, int);

bool sortByLastDigit(int a, int b)
{
	int aLast = a % 10;
	int bLast = b % 10;

	if (aLast < 0)
		aLast *= (-1);

	if (bLast < 0)
		bLast *= (-1);

	if (aLast > bLast)
		return true;

	else if (aLast < bLast)
		return false;

	return a > b;
}

bool sortByAbs(int a,int b)
{
	if (a < 0)
		a*= (-1);

	if (b < 0)
		b *= (-1);

	return (a > b);
}

void swap(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int arr[], int n, sortingCriteria sc)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (sc(arr[j] , arr[j + 1]))
				swap(arr[j], arr[j + 1]);
}

void printIntArray(int* arr, int countOfNumbers)
{
	for (int i = 0; i < countOfNumbers; i++)
		cout << arr[i] << " ";

	cout << '\n';
}

int main()
{
	//Tests
	int arr[7] = {95,8,13,123,4567,-12,-113};

	bubbleSort(arr,7,sortByLastDigit);
	printIntArray(arr,7);
	//-12, -113, 13, 123, 95, 4567, 8

	bubbleSort(arr,7,sortByAbs);
	printIntArray(arr,7);
	//8, -12, 13, 95, -113, 123, 4567
}