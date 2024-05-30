#include <iostream>
#include "insertionsort.cpp"

int main()
{
    const int n = 5;
    int arr[n] = {5, 4, 3, 2, 1};

    printarray(n, arr);
    insertionsort(n, arr);
    printarray(n, arr);
}