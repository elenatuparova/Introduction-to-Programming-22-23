#include <iostream>

typedef bool (*sortBy)(int, int);


void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;   
}

bool firstNumberLastDigBiggerThanSecondNumberLD(int a, int b)
{
    int lastDigit1 = a % 10;
    int lastDigit2 = b % 10;
    if (lastDigit1 == lastDigit2)
    {
        return a > b;
    }

    return lastDigit1 > lastDigit2;
    
}

void sortArray(int* arr, int arrSize, sortBy method)
{

    for (int i = 0; i < arrSize - 1; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < arrSize - i - 1; j++)
        {
            if (method(arr[j],arr[j+1]))
            {
                swap(arr[j],arr[j + 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped) 
        {
            return;
        }
    }
}


int main()
{
    int arrSize = 0;
    std::cin >> arrSize;

    int* array = new int[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        std::cin >> array[i];
    }

    sortArray(array, arrSize, firstNumberLastDigBiggerThanSecondNumberLD);
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << array[i]<<" ";
    }

    delete[] array;   
}

