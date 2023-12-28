#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    // swap the values of a and b
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            // traverse the array from 0 to n - i - 1
            // swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}