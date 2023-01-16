#include <iostream>
const int MAX = 5;
//Да се напише рекурсивна функция, която намира
//сумата на елементите на масив от цели числа.
void initialize(int* array, int size) {
	for (int i = 0; i < size; i++)
	{
		std::cin >> array[i];
	}
}

int sum(int* array, int index)
{
	if (index == MAX)
	{
		return 0;
	}
	return array[index] + sum(array, index + 1);
	
	/*return (index == MAX) ? 0 : sum(array, index + 1)+array[index];*/
}

int main()
{
	int myArray[MAX] = { 0, };
	int result = 0;
	initialize(myArray, MAX);
	std::cout << sum(myArray, 0);


	return 0;
}