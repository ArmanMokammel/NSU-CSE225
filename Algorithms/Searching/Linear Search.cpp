#include <iostream>

using namespace std;

/*
    --LINEAR SEARCH--

    Time Complexity: 
        Best Case: O(1); When the element being searched is the first element in the list.

        Worst & Average Case: O(N); In the worst case, the key might be present at the last index i.e., opposite to the end from which the search has started in the list. Where N is the size of the list.
*/

int LinearSearch(int *arr, int n, int target)
{
    // Going through array sequencially
    for (int i = 0; i < n; i++)
    {
        //If found, return the index
        if (arr[i] == target)
            return i;
    }

    //Not Found
    return -1;
}

int main()
{
    int arr[] = {2, 4, 0, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int target = 3;

    int result = LinearSearch(arr, n, target);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}