#include <iostream>

int* createAndInitializeArray(int size) {
	int* arr = new int[size] {};
	//for (int i = 0; i < size; i++) {
	//	arr[i] = 0;
	//}
	return arr;
}

void inputArray(int* myArray, int size) {
	for (int i = 0; i < size; i++) {
		std::cin >> myArray[i];
	}
}

void printArray(const int* myArray, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;
}

void deleteArray(int* myArray) {
	delete[] myArray;
}

int* mergeArrays(const int* first, const int* second, int firstSize, int secondSize) {
	int mergedSize = firstSize + secondSize;
	int* merged = createAndInitializeArray(mergedSize);

	int firstIdx = 0, secondIdx = 0, mergedIdx = 0;

	while (firstIdx < firstSize && secondIdx < secondSize) {
		if (first[firstIdx] < second[secondIdx]) {
			merged[mergedIdx] = first[firstIdx];
			firstIdx++;
		}
		else {
			merged[mergedIdx] = second[secondIdx];
			secondIdx++;
		}
		mergedIdx++;
	}

	while (firstIdx < firstSize) {
		merged[mergedIdx] = first[firstIdx];
		firstIdx++;
		mergedIdx++;
	}

	while (secondIdx < secondSize) {
		merged[mergedIdx] = second[secondIdx];
		secondIdx++;
		mergedIdx++;
	}

	return merged;
}

int main() {
	int first[] = { 1, 4, 7, 9 };
	int second[] = { 2, 3, 7, 8, 12 };
	int* merged = mergeArrays(first, second, 4, 5);
	printArray(merged, 9);
	deleteArray(merged);
}