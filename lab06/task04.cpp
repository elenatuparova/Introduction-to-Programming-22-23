#include <iostream>

const int MIN_N = 1;
const int MAX_N = 10;
const int MIN_M = 1;
const int MAX_M = 20;
const int MIN_K = 0;

void inputMatrix(int matrix[][MAX_M], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

void printMatrix(const int matrix[][MAX_M], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
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
	
	int k = 0;
	std::cin >> k;
	if (k < MIN_K || k >= m) {
		std::cout << "Invalid k";
		return 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = k; j < m - 1; j++) {
			A[i][j] = A[i][j + 1];
		}
	}
	m--;

	printMatrix(A, n, m);

	return 0;
}