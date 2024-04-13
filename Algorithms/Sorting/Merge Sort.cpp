#include <iostream>

using namespace std;

/*
    --MERGE SORT--

    Time Complexity: O(nlog2 n);
*/

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int* L = new int[n1];
    int* M = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
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

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
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

    delete [] L;
    delete [] M;
}


void mergeSort(int* arr, int p, int r){
	if(p>=r)
		return;
	int q = (p+r)/2;
	mergeSort(arr, p, q); // left subarray
	mergeSort(arr, q+1, r); //right subarray
	merge(arr, p, q, r);
}

int main() {
	// your code goes here
	
	int A[] = {35, 27, 53, 14, 10, 50, 60, 35};
	for(int i=0; i<8; i++)
		cout << A[i] << " ";

    cout << "\n";	
	
	mergeSort(A, 0, 7);
	
	for(int i=0; i<8; i++)
		cout << A[i] << " ";
		
	return 0;
}