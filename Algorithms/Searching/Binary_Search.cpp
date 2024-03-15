#include <iostream>

using namespace std;

/*
    --BINARY SEARCH--
    
    Conditions:
    1. The array must be sorted

    Time Complexity: 
        Best Case: O(1); If the element is found in the middle through the first iteration.

        Average & Worst Case: O(log2 n); Where n is the number of elements in the sorted array. This means that the time taken to search for an element in the array grows logarithmically as the size of the array increases. Binary search works by repeatedly dividing the search interval in half. In each step, it discards half of the elements, which leads to a logarithmic time complexity. 2 because array is split into 2.
*/

int Binary_Search(int *arr, int n, int target)
{
    int low = 0, high = n-1; //Indexes
    
    // Repeat until the pointers low and high meet each other
    while (low <= high)
    {
        int mid = low + (high-low)/2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]); //Size of array

    int target = 39;

    int result = Binary_Search(arr, n, target);

    if (result != -1)
    {
        cout << "Element is present at index: " << result << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}
