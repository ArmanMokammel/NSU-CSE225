#include <iostream>

using namespace std;

/*
    --SELECTION SORT--

    Time Complexity: O(n*n = n^2); It requires 2 loops
*/

void selectionSort(int arr[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        //Take the step position as the initial min index
        int minIndex = step;

        //Now check all the right side elements
        for (int i = step + 1; i < size; i++)
        {
            // Select the minimum element in each loop.
            if (arr[i] < arr[minIndex])
                minIndex = i;
        }

        //Now swap the minimum element with the step position element
        int temp = arr[minIndex];
        arr[minIndex] = arr[step];
        arr[step] = temp;
    }
}

int main()
{
    int arr[] = {20, 12, 10, 15, 2};

    // find array's length
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << "\n";


    return 0;
}