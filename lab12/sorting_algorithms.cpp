#include <iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int myArray[], int size) {
	// bool swapped = false;
	for (int i = 0; i < size - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < size - i - 1; j++) {
			if (myArray[j] > myArray[j + 1]) {
				swap(myArray[i], myArray[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			return;
		}
	}
}

void selectionSort(int myArray[], int size) {
	int minimalIndex = 0;
	for (int i = 0; i < size - 1; i++) {
		minimalIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (myArray[minimalIndex] > myArray[j]) {
				minimalIndex = j;
			}
		}
		swap(myArray[i], myArray[minimalIndex]);
	}
}

void printArray(int myArray[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << myArray[i] << " ";
	}
	std::cout << endl;
}

int main() {
	const int SIZE = 5;
	int myArray[SIZE] = { 2, 8, 1, 6, 0 };
	printArray(myArray, SIZE);

	selectionSort(myArray, SIZE);
	printArray(myArray, SIZE);

	return 0;
}