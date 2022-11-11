#include <iostream>

const int MIN_SIZE = 1;
const int MAX_SIZE = 100;

const int SORTED_SIZE = 6;

int searchNumber(const int myArray[], int size, int x) {
	for (int i = 0; i < size; i++) {
		if (myArray[i] == x) {
			return i;
		}
	}
	return -1;
}

// only for already sorted arrays!
int binarySearch(const int myArray[], int size, int x) {
	int left = 0;
	int right = size - 1;
	int middle;

	while (left < right) {
		middle = left + (right - left) / 2;
		if (myArray[middle] == x) {
			return middle;
		}
		else if (myArray[middle] > x) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	return -1;
}

void inputArray(int myArray[], int size) {
	for (int i = 0; i < size; i++) {
		std::cin >> myArray[i];
	}
}

void printArray(const int myArray[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int numbers[MAX_SIZE];
	int numbersCount = 0;
	std::cin >> numbersCount;
	if (numbersCount > MAX_SIZE || numbersCount < MIN_SIZE) {
		std::cout << "Invalid array size";
		return 1;
	}

	inputArray(numbers, numbersCount);

	int numberToSearch = 0;
	std::cin >> numberToSearch;

	std::cout << searchNumber(numbers, numbersCount, numberToSearch) << std::endl;

	int sortedNumbers[SORTED_SIZE] = { 1, 4, 5, 8, 9, 12 };
	std::cout << binarySearch(sortedNumbers, SORTED_SIZE, 5) << std::endl;
	std::cout << binarySearch(sortedNumbers, SORTED_SIZE, 10) << std::endl;

	return 0;
}