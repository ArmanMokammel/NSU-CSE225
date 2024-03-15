#include <iostream>

using namespace std;

int main()
{
    //Making a new int pointer
    int *n = new int;
    cout << "Enter size of array: ";
    //Store the value at the memory address of n
    cin >> *n;

    //Creating a array of dynamic (user-defined) size
    int *arr = new int[*n];

    for(int i = 0; i < *n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        //Storing values into array (without using pointer)
        //Can also use pointers
        cin >> arr[i];
    }

    for(int i = 0; i < *n; i++)
    {
        //Using pointer to get values from array
        cout << *(arr+i) << ", ";
    }

    //De-allocate array
    delete [] arr;

    return 0;
}
