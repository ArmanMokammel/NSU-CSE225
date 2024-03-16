#include <iostream>

using namespace std;

/*
    --INSERTION SORT--

    Time Complexity: O(n*n = n^2); It requires 2 loops
*/

void insertionSort(int arr[], int size)
{
    //Starting from index = 1
    for (int step = 1; step < size; step++) 
    {
        //Take the element as a key
        int key = arr[step];
        //Start from the element just beside the key
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than it is found
        while (key < arr[j] && j >= 0) 
        {
            //Put the value of the target spot to the right
            arr[j + 1] = arr[j];
            j--;

            //Keep doing this until end of left end of array is reached or placement position is found
        }
        //Add 1 to j as it has decreased one less. Put the key in that position
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {9, -5, 1, 4, 3};

    // find array's length
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << "\n";

    return 0;
}