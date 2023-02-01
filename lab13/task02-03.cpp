#include <iostream>

void print(int arr[], int length) {
    for(int i = 0; i < length; i++) {
        std::cout << arr[i];
        if(i != length - 1) {
            std::cout << " ";
        }
        else {
            std::cout << std::endl;
        }
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortArray(int arr[], int length, bool (*criteria)(int, int)) {
    for(int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - 1 - i; j++) {
            if(criteria(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

bool byLastDigit(int a, int b) {
    if(a % 10 == b % 10 && a > b) {
        return true;
    }
    if(a % 10 > b % 10) {
        return true;
    }
    return false;
}

int abs(int number) {
    return number > 0 ? number : -number;
}

bool byAbsValue(int a, int b) {
    return abs(a) < abs(b);
}

int main() {
    int numbers[] = {-95, 8, -13, 123, 4567}, length = 5;
    sortArray(numbers, length, byLastDigit);
    print(numbers, length);
    sortArray(numbers, length, byAbsValue);
    print(numbers, length);
    return 0;
}
