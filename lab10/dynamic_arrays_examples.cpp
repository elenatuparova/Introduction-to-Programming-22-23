#include <iostream> 

int main() {

	// example 1
	int N = 0;
	std::cin >> N;

	// syntax for creating a 1D dynamic array (you can create functions here)
	int* myArray = new int[N];
	for (int i = 0; i < N; i++) {
		std::cin >> myArray[i];
	}

	// ..... modifications

	delete[] myArray; // always remember to deallocate the dynamic memory!

	// example 2
	int M = 0;
	int K = 0;
	std::cin >> M >> K;

	// syntax for creating a 2D dynamic array (you can create functions here)
	int** myMatrix = new int*[M];
	for (int i = 0; i < M; i++) {
		myMatrix[i] = new int[K];
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			std::cin >> myMatrix[i][j];
		}
	}

	// ..... modifications

	for (int i = 0; i < M; i++) {
		delete[] myMatrix[i];
	}
	delete[] myMatrix; // pay attention to the order in which we deallocate the memory!

	return 0;
}