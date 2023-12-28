#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // key is the element to be inserted
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            // shift the elements to the right
            arr[j + 1] = arr[j];
            j--;
        }
        // insert the element at its correct position
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}