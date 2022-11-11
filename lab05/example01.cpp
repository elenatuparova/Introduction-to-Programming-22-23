#include <iostream>

const int SIZE = 10;

void inputArray(int myArray[], int size) {
	for (int i = 0; i < size; i++) {
		std::cin >> myArray[i];
	}
}

void printArrayBackwards(const int myArray[], int size) {
	for (int i = size - 1; i >= 0; i--) {
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int numbers[SIZE];
	inputArray(numbers, SIZE);
	printArrayBackwards(numbers, SIZE);

	// alternatively if you don't use the above functions
	/*for (int i = 0; i < SIZE; i++) {
		std::cin >> numbers[i];
	}

	for (int i = SIZE - 1; i >= 0; i--) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;*/

	return 0;
}