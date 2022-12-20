#include <iostream>

void resize(int* &array, int& size) {
	int* newArray = new int[size * 2];
	for (int i = 0; i < size; i++) {
		newArray[i] = array[i];
	}
	size *= 2;
	delete[] array;
	array = newArray;
}

void addNumberToArray(int*& array, int& currentNumbersCount, int& size, int number) {
	if (currentNumbersCount < size) {
		array[currentNumbersCount++] = number;
		return;
	}

	resize(array, size);
	array[currentNumbersCount++] = number;
}

int main() {
	int size = 5;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	int currentNumbersCount = 5;
	addNumberToArray(arr, currentNumbersCount, size, 5);
	std::cout << arr[5] << std::endl; // this is where the new element will be added
	delete[] arr;
	return 0;
}