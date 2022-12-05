//  Author: Anish Tilloo
//  Roll No. : 34
//  Program: Heap Sort

#include <bits/stdc++.h>
using namespace std;

// Heap Sort
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// here we are checking if the left child index is greater than n or not 
    // and the left child is greater than the current element
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// here we are checking if the right child index is greater than n or not 
    // and the right child is greater than the current element
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
		

	for (int i = n - 1; i >= 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

void inputArray( int arr[], int arraySize){
    cout << "Enter the elements of the array one by one " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cin >> arr[i];
    }
}


void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
    int n;
    cout << "Enter the no of elements in the array" << endl;
    cin >> n;
    int arr[n];
    inputArray(arr, n);
    
	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
}
