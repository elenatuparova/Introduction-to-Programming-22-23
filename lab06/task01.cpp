#include <iostream>

const int MIN_N = 1;
const int MAX_N = 20;
const int MIN_M = 1;
const int MAX_M = 30;

void inputMatrix(int matrix[][MAX_M], int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

void printMatrix(const int matrix[][MAX_M], int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;

	if (n < MIN_N || n > MAX_N || m < MIN_M || m > MAX_M) {
		std::cout << "Invalid matrix size";
		return 1; // alternatively you can use an else clause here
	}

	int A[MAX_N][MAX_M];
	inputMatrix(A, n, m);

	int B[MAX_N][MAX_M];
	inputMatrix(B, n, m);

	int C[MAX_N][MAX_M];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	printMatrix(C, n, m);

	return 0;
}