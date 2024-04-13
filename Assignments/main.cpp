#include <iostream>
#include <time.h>

using namespace std;

void bubbleSort(int array[], int size)
{
    for(int step = 0; step < size; step++)
    {
        for(int i = 0; i < size-step; i++)
        {
            if (array[i] > array[i + 1]) 
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int minIndex = step;

        for (int i = step + 1; i < size; i++)
        {
            if (arr[i] < arr[minIndex])
                minIndex = i;
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[step];
        arr[step] = temp;
    }
}

void insertionSort(int arr[], int size)
{
    for (int step = 1; step < size; step++) 
    {
        int key = arr[step];
        int j = step - 1;

        while (key < arr[j] && j >= 0) 
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void merge(int arr[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int p, int r){
	if(p>=r)
		return;
	int q = (p+r)/2;
	mergeSort(arr, p, q);
	mergeSort(arr, q+1, r);
	merge(arr, p, q, r);
}

int partition(int arr[],int low,int high)
{   
  int pivot=arr[high];
  int i=(low-1);
   
  for(int j=low;j<=high;j++)
  {
    if(arr[j]<pivot)
    {
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}
             
void quickSort(int arr[],int low,int high)
{
  if(low<high)
  {     
    int pi=partition(arr,low,high);
     
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}

int main()
{
    cout << "\e[1m\e[32m[Setting up datasets - START]\n" << endl;

    const int size_1 = 50000;
    const int size_2 = 15000;
    const int size_3 = 20000;
    const int size_4 = 10000;

    int dataset_1[size_1];
    int dataset_2[size_2];
    int dataset_3[size_3];
    int dataset_4[size_4];

    cout << "\e[0mStarting to fill dataset 1" << endl;
    int value;
    for(int i = 0; i < size_1; i++)
    {
        value = rand();
        dataset_1[i] = value;
    }
    cout << "Dataset 1 of size " << size_1 << " is ready!\n" << endl;

    cout << "Starting to fill dataset 2" << endl;
    for(int i = 0; i < size_2; i++)
    {
        value = rand();
        dataset_2[i] = value;        
    }
    cout << "Dataset 2 of size " << size_2 << " is ready!\n" << endl;

    cout << "Starting to fill dataset 3" << endl;
    for(int i = 0; i < size_3; i++)
    {
        value = rand();
        dataset_3[i] = value;        
    }
    cout << "Dataset 3 of size " << size_3 << " is ready!\n" << endl;

    cout << "Starting to fill dataset 4" << endl;
    for(int i = 0; i < size_4; i++)
    {
        value = rand();
        dataset_4[i] = value;
    }
    cout << "Dataset 4 of size " << size_4 << " is ready!\n" << endl;
    cout << "\e[1m\e[32m[Setting up datasets - END]\n" << endl;

    clock_t req_time;

    /* 
       ---- Bubble Sort Algorithm Region Start ----
    */

    cout << "\e[1m\e[32m[Bubble Sort Algorithm Setup - START]\n" << endl;

    cout << "\e[0mCopy Dataset 1 to new temporary array\n" << endl;
    int temp_1[size_1];
    
    copy(dataset_1, dataset_1+size_1, temp_1);

    cout << "Executing Bubble Sort on Dataset 1 copy" << endl;
    req_time = clock();
    bubbleSort(temp_1, size_1);
    req_time = clock() - req_time;
    cout << "Time taken for Bubble Sort on Dataset 1: " << (float)req_time/CLOCKS_PER_SEC << "s\n" << endl;
    delete [] &temp_1;

    cout << "Copy Dataset 2 to new temporary array\n" << endl;
    int temp_2[size_2];

    copy(dataset_2, dataset_2+size_2, temp_2);

    cout << "Executing Bubble Sort on Dataset 2 copy" << endl;
    req_time = clock();
    bubbleSort(temp_2, size_2);
    req_time = clock() - req_time;
    cout << "Time taken for Bubble Sort on Dataset 2: " << (float)req_time/CLOCKS_PER_SEC << "s\n" << endl;
    delete [] &temp_2;

    cout << "Copy Dataset 3 to new temporary array\n" << endl;
    int temp_3[size_3];

    copy(dataset_3, dataset_3+size_3, temp_3);

    cout << "Executing Bubble Sort on Dataset 3 copy" << endl;
    req_time = clock();
    bubbleSort(temp_3, size_3);
    req_time = clock() - req_time;
    cout << "Time taken for Bubble Sort on Dataset 3: " << (float)req_time/CLOCKS_PER_SEC << "s\n" << endl;
    delete [] &temp_3;

    cout << "Copy Dataset 4 to new temporary array\n" << endl;
    int temp_4[size_4];

    copy(dataset_4, dataset_4+size_4, temp_4);

    cout << "Executing Bubble Sort on Dataset 4 copy" << endl;
    req_time = clock();
    bubbleSort(temp_4, size_4);
    req_time = clock() - req_time;
    cout << "Time taken for Bubble Sort on Dataset 4: " << (float)req_time/CLOCKS_PER_SEC << "s\n" << endl;
    delete [] &temp_4;

    cout << "\e[1m\e[32m[Bubble Sort Algorithm Setup - END]\n" << endl;

    /* 
       ---- Bubble Sort Algorithm Region End ----
    */

   /* 
       ---- Selection Sort Algorithm Region Start ----
    */

    cout << "\e[1m\e[32m[Selection Sort Algorithm Setup - START]\n" << endl;

    cout << "\e[0mCopy Dataset 1 to new temporary array\n" << endl;
    int temp_5[size_1];
    
    copy(dataset_1, dataset_1+size_1, temp_5);

    cout << "Executing Selection Sort on Dataset 1 copy" << endl;
    req_time = clock();
    selectionSort(temp_5, size_1);
    req_time = clock() - req_time;
    cout << "Time taken for Selection Sort on Dataset 1: " << (float)req_time/CLOCKS_PER_SEC << "s\n" << endl;
    delete [] &temp_5;

    cout << "Copy Dataset 2 to new temporary array\n" << endl;
    int temp_6[size_2];

    copy(dataset_2, dataset_2+size_2, temp_6);

    cout << "Executing Selection Sort on Dataset 2 copy" << endl;
    req_time = clock();
    selectionSort(temp_6, size_2);
    req_time = clock() - req_time;
    cout << "Time taken for Selection Sort on Dataset 2: " << (float)req_time/CLOCKS_PER_SEC << "s\n" << endl;
    delete [] &temp_6;

    cout << "Copy Dataset 3 to new temporary array\n" << endl;
    int temp_7[size_3];

    copy(dataset_3, dataset_3+size_3, temp_7);

    cout << "Executing Selection Sort on Dataset 3 copy" << endl;
    req_time = clock();
    selectionSort(temp_7, size_3);
    req_time = clock() - req_time;
    cout << "Time taken for Selection Sort on Dataset 3: " << (float)req_time/CLOCKS_PER_SEC << "s\n" << endl;
    delete [] &temp_7;

    cout << "Copy Dataset 4 to new temporary array\n" << endl;
    int temp_8[size_4];

    copy(dataset_4, dataset_4+size_4, temp_8);

    cout << "Executing Selection Sort on Dataset 4 copy" << endl;
    req_time = clock();
    selectionSort(temp_8, size_4);
    req_time = clock() - req_time;
    cout << "Time taken for Selection Sort on Dataset 4: " << (float)req_time/CLOCKS_PER_SEC << "s\n" << endl;
    delete [] &temp_8;

    cout << "\e[1m\e[32m[Selection Sort Algorithm Setup - END]\n" << endl;

    /* 
       ---- Selection Sort Algorithm Region End ----
    */

    return 0;
}