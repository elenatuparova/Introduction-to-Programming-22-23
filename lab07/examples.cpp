#include <iostream>

// example 1 with & (bitwise AND)
bool isEvenAND(unsigned int number) {
	return (!(number & 1));
}

// example 1 with | (bitwise OR)
bool isEvenOR(unsigned int number) {
	return (number | 1) > number;
}

//example 1 with ^ (bitwise XOR)
bool isEvenXOR(unsigned int number) {
	return (number ^ 1) == number + 1;
}

// example 2
unsigned int twoPow(unsigned int pow) {
	return 1 << pow;
}

int main() {
	// try out the above functions

	return 0;
}