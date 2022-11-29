#include <iostream>

int getLength(const char myString[]) {
	int index = 0;
	while (myString[index] != '\0') {
		index++;
	}
	return index;
}

int getLengthWithPointer(const char* myString) {
	if (myString == nullptr) { // it's always good to check just in case, applies to the other functions as well
		return -1;
	}

	int length = 0;
	while (*myString != '\0') {
		length++;
		myString++;
	}
	return length;
}

int compareStrings(const char first[], const char second[]) {
	int index = 0;

	while (first[index] == second[index]) {
		if (first[index] == '\0') {
			return 0;
		}
		index++;
	}

	return first[index] - second[index];
}

void copyString(char* dest, const char* source) {
	// TODO make sure that destination string has enough space!
	int index = 0;
	while (source[index] != '\0') {
		dest[index] = source[index];
		index++;
	}

	dest[index] = '\0';
}

const int ALPHABET_SIZE = 26;

char getMostFrequentSymbol(const char myString[]) {
	int frequency[ALPHABET_SIZE] = { 0 };
	//for (int i = 0; i < ALPHABET_SIZE; i++) {
	//	frequency[i] = 0;
	//}

	int index = 0;
	while (myString[index] != '\0') {
		frequency[myString[index] - 'a']++;
		index++;
	}
	int currentMaxIndex = 0;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (frequency[i] > frequency[currentMaxIndex]) {
			currentMaxIndex = i;
		}
	}
	return currentMaxIndex + 'a';
}

const int MAX_SIZE = 100;

int main()
{
	char first[] = "abde";

	std::cout << getLength(first) << std::endl;
	std::cout << getLengthWithPointer(first) << std::endl;
	std::cout << first << std::endl;

	char second[] = "abd";
	if (compareStrings(first, second) == 0) {
		std::cout << "equal";
	}
	else if (compareStrings(first, second) < 0) {
		std::cout << "first is before second";
	}
	else {
		std::cout << "first is after second";
	}

	std::cout << std::endl;

	char myStr[MAX_SIZE];
	std::cin.getline(myStr, MAX_SIZE);
	std::cout << getMostFrequentSymbol(myStr);

	return 0;
}