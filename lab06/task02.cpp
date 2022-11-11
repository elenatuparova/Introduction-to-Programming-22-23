#include <iostream>

const int MIN_N = 1;
const int MAX_N = 20;

void inputSquareMatrix(int matrix[][MAX_N], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

void printSquareMatrix(const int matrix[][MAX_N], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int sumMainDiagonal(int matrix[][MAX_N], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += matrix[i][i];
	}
	return sum;
}

int sumOverMainDiagonal(int matrix[][MAX_N], int n) {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}

int main() {
	int n;
	std::cin >> n;

	if (n < MIN_N || n > MAX_N) {
		std::cout << "Invalid matrix size";
		return 1; // alternatively you can use an else clause here
	}

	int A[MAX_N][MAX_N];
	inputSquareMatrix(A, n);
	
	std::cout << sumMainDiagonal(A, n) << std::endl;
	std::cout << sumOverMainDiagonal(A, n) << std::endl;

	return 0;
}