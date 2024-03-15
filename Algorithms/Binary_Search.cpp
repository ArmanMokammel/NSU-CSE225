#include <iostream>

using namespace std;

/*
    --BINARY SEARCH--
    
    Conditions:
    1. The array must be sorted

    Time Complexity: O(log n); Where n is the number of elements in the sorted array. This means that the time taken to search for an element in the array grows logarithmically as the size of the array increases.

    Space Complexity: O(1); Which indicates that the amount of memory required by the algorithm remains constant regardless of the size of the input array.
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
