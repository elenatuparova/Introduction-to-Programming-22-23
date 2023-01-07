#include <iostream>

const int MAX_SIZE = 100;

void input(int* numbers, int& N) {
	std::cout << "Enter elements count: " << std::endl;
	std::cin >> N;
	std::cout << "Elements:" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cin >> numbers[i];
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void sort(int* numbers, int N) {
	for (int i = 1; i < N; i++) {
		int firstLastDigit = numbers[i - 1] % 10;
		int secondLastDigit = numbers[i] % 10;
		if (firstLastDigit > secondLastDigit || (firstLastDigit == secondLastDigit && numbers[i - 1] > numbers[i])) {
			swap(numbers[i - 1], numbers[i]);
			i = 0;
		}
	}
}

void output(int* numbers, int N) {
	std::cout << "Sorted:" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << numbers[i] << " ";
	}
}

int main() {
	int N = 0;
	int numbers[MAX_SIZE];
	input(numbers, N);
	sort(numbers, N);
	output(numbers, N);
}