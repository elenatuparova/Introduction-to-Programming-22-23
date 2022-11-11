#include <iostream>

const int N = 5; // rows
const int M = 6; // columns

int main() {
	int A[N][M];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> A[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}