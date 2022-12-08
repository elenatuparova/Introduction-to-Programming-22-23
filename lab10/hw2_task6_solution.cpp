#include <iostream>

const int DIGITS_COUNT = 10;
const int MIN_START = 1;
const int MAX_END = 1 << 31 - 1;

int myPow(int number, int power) {
    int product = 1;
    for (int i = 0; i < power; i++) {
        product *= number;
    }
    return product;
}

bool isEven(int number) {
    return (number % 2 == 0);
}

bool isDivisibleByPowerOfTen(int number, int power) {
    return (number % myPow(10, power) == 0);
}

int countDigits(int number, int* digitFrequencies) {
    int numberCopy = number;
    int currentDigit = 0;
    int digitCount = 0;
    while (numberCopy != 0) {
        currentDigit = numberCopy % 10;
        digitFrequencies[currentDigit]++;
        digitCount++;
        numberCopy /= 10;
    }
    return digitCount;
}

int countOddFrequencies(const int* digitFrequencies) {
    int oddCount = 0;

    for (int i = 0; i < DIGITS_COUNT; i++) {
        if (!isEven(digitFrequencies[i])) {
            oddCount++;
        }
    }

    return oddCount;
}

bool isHalfPalindrome(int number) {
    if (number < 100) {
        return false;
    }

    int digitFrequencies[DIGITS_COUNT] = { 0 };
    int digitCount = countDigits(number, digitFrequencies);

    if (isDivisibleByPowerOfTen(number, digitCount - 1)) {
        return false;
    }

    int oddCount = countOddFrequencies(digitFrequencies);

    if (isEven(digitCount) && oddCount > 0) {
        return false;
    }
    else if (!isEven(digitCount) && oddCount > 1) {
        return false;
    }
    else {
        return true;
    }

}

bool isValid(int number, int lowerBound, int upperBound) { // useful if you want to validate more variables with different ranges
    if (number < lowerBound || number > upperBound) {
        return false;
    }
    return true;
}

bool validateStartAndEnd(int start, int end) {
    if (start > end || !isValid(start, MIN_START, MAX_END) || !isValid(end, MIN_START, MAX_END)) {
        return false;
    }
    return true;
}

int countHalfPalindromes(int start, int end) {
    if (!validateStartAndEnd(start, end)) {
        return -1;
    }

    int halfPalindromeCount = 0;
    for (int i = start; i <= end; i++) {
        if (isHalfPalindrome(i)) {
            halfPalindromeCount++;
        }
    }

    return halfPalindromeCount;
}

int main()
{
    int start = 0;
    int end = 0;
    std::cin >> start >> end;

    std::cout << countHalfPalindromes(start, end) << std::endl;

    return 0;
}