#include <iostream>

// example 1
long long factorial(int number) {
	if (number < 0) { // data validation
		return -1;
	}
	if (number == 0) {
		return 1;
	}
	return number * factorial(number - 1);
}

// example 2
int fibonacci(int N) {
	if (N < 0) {
		return -1;
	}
	if (N == 0 || N == 1) {
		return N;
	}
	return fibonacci(N - 1) + fibonacci(N - 2);
}

// task 1
// will execute a total of pow operations
long long power(int number, int pow) {
	if (pow == 0) {
		return 1;
	}
	return number * power(number, pow - 1);
}

// will execute a total of log2(pow) operations
long long power2(int number, int pow) {
	if (pow == 0) {
		return 1;
	}
	if (pow % 2 == 0) {
		long long current = power2(number, pow / 2);
		return current * current;
	}
	else {
		return number * power2(number, pow - 1);
	}
}

// task 2
int binarySearchIterative(const int* myArray, int size, int x) {
	int left = 0;
	int right = size - 1;
	int middle;

	while (left <= right) {
		middle = left + (right - left) / 2;

		if (myArray[middle] == x) {
			return middle;
		}

		if (myArray[middle] > x) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	return -1;
}

int binarySearchRecursive(const int* myArray, int x, int left, int right) {
	if (left > right) {
		return -1;
	}
	int middle = left + (right - left) / 2;
	if (myArray[middle] == x) {
		return middle;
	}
	if (myArray[middle] > x) {
		return binarySearchRecursive(myArray, x, left, middle - 1);
	}
	if (myArray[middle] < x) {
		return binarySearchRecursive(myArray, x, middle + 1, right);
	}
}