#include <iostream>

using namespace std;

// perform bubble sort
void bubbleSort(int array[], int size)
{
    // loop to access each array element from left to right
    for(int step = 0; step < size; step++)
    {
        // loop to compare array elements from left to right
        for(int i = 0; i < size-step; i++)
        {
            // compare two adjacent elements
            if (array[i] > array[i + 1]) 
            {
                // swapping elements if elements are not in the intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {-2, 45, 0, 11, -9};

    // find array's length
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << "\n";

    return 0;
}