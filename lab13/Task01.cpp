#include <iostream>

using namespace std;
typedef bool(*criteria) (int, int);

bool SortByLastDigit(int a, int b)
{
    if (a % 10 > b % 10) return true;
    return a > b;
}
bool SortByAbs(int a, int b)
{
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;
    return a > b;
}

void SortArray(int* arr, int arrLenght, criteria c)
{
    for (int i = 0; i < arrLenght - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < arrLenght - i - 1; j++)
        {
            if (c(arr[j], arr[j + 1]))
            {
                swapped = true;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (!swapped) return;
    }
}
int main()
{
    int arr[4] = { 2047, -12452, 1355, 2457 };
    int arrLenght = 4;
    SortArray(arr, arrLenght, SortByLastDigit);
    for (int i = 0; i < arrLenght; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    SortArray(arr, arrLenght, SortByAbs);
    for (int i = 0; i < arrLenght; i++)
    {
        cout << arr[i] << " ";
    }
}