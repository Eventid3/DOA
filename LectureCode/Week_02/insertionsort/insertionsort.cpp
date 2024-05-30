#include <cassert>

void printarray(int n, int* arr)
{
    for (int i = 0; i < n; i++)
        {
            std::cout << arr[i] << " ";
        }
    std::cout << "\n";
}

void swap (int a, int b, int* x, int n)
{
    //assert

    int t;
    t = x[a];
    x[a] = x[b];
    x[b] = t;
}

void insertionsort(int n, int* x)
{
    // assert

    for (int i = 1; i < n; ++i)
    {
        int j = i;

        for (; j > 0; j--)
        {
            if (x[j] > x[j-1])
                break;
            else
            {
                swap(j, j-1, x, n);
                printarray(n,x); // for debugging
            }
        }
    }

}