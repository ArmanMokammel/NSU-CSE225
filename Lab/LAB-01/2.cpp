#include <iostream>

using namespace std;

int main()
{
    int row, column;

    cout << "Enter row: ";
    cin >> row;
    cout << "Enter column: ";
    cin >> column;

    //Create an array of pointers
    int **arr = new int*[row];

    //For each pointer of the array, create another array and make it point to it
    for(int i = 0; i < row; i++)
    {
        arr[i] = new int[column];
    }

    //Now input the values into the 2d array as usual
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cout << "Enter arr[" << i << "][" << j << "] = ";
            //cin >> arr1[i][j];
            cin >> *(*(arr+i)+j); //Also works
        }
    }

    //Now print the 2d array as usual
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //Free each sub-array
    for(int i = 0; i < row; ++i) {
        delete[] arr[i];
    }
    //Free the array of pointers
    delete[] arr;

    return 0;
}
