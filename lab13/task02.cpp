#include <iostream>

typedef bool (*CriteriaToSortBy) (int, int);

inline int LastDigit(int num) {
	return num % 10;
}

bool Num1LastDigitGreaterThanNum2LastDigit(int num1, int num2) {
	const int num1LastDigit = LastDigit(num1),
		num2LastDigit = LastDigit(num2);

	if (num1LastDigit != num2LastDigit) {
		return num1LastDigit > num2LastDigit;
	}

	return num1 > num2;
}

void Swap(int& num1, int& num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void SortArray(int* array, int arraySize, CriteriaToSortBy criteria) {
	const int lastIndex = arraySize - 1;
	int lastSortedIndex = 0;
	bool hasSwapped = false;

	for (size_t i = 0; i < lastIndex; i++) {
		lastSortedIndex = lastIndex - i;
		hasSwapped = false;

		for (size_t j = 0; j < lastSortedIndex; j++) {
			if (criteria(array[j], array[j + 1])) {
				Swap(array[j], array[j + 1]);
				hasSwapped = true;
			}
		}

		if (!hasSwapped) {
			return;
		}
	}
}

void PrintArray(int* array, int arraySize) {
	for (size_t i = 0; i < arraySize; i++) {
		std::cout << array[i] << ' ';
	}
}

int main() {
	int arrSize = 0;
	std::cin >> arrSize;

	int* arr = new int[arrSize];

	for (size_t i = 0; i < arrSize; i++) {
		std::cin >> arr[i];
	}

	SortArray(arr, arrSize, Num1LastDigitGreaterThanNum2LastDigit);
	PrintArray(arr, arrSize);

	delete[] arr;

	return 0;
}