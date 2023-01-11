#include <iostream>
void swap(int& num1, int& num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
void specialSortByLastDigit(int * arr, int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            int lastDig = arr[j] % 10;
            int nextDig = arr[j + 1] % 10;
            if(lastDig > nextDig){
                swap(arr[j], arr[j + 1]);
            }
            if(lastDig == nextDig){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void printArr(const int * arr, int len){
    for(int i = 0; i < len; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
