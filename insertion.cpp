#include <iostream>
using namespace std;

int main()
{
    int n, i, j, key;
    int a[100];

    // Input number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    // Input array elements
    cout << "Enter " << n << " elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Insertion Sort
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        // Insert key at correct position
        a[j + 1] = key;
    }

    // Display sorted array
    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}