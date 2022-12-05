//  Author: Anish Tilloo
//  Roll No. : 34
//  Program: Bubble Sort

#include <bits/stdc++.h>
using namespace std;

// Bubble Sort Algorithm
void bubbleSort(int n, int arr[]){
    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swaping if the number is greater than the next one
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void inputArray( int arr[], int arraySize){
    cout << "Enter the elements of the array one by one " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cin >> arr[i];
    }
}

void printArray(int arr[], int arraySize){
    for (int i = 0; i < arraySize; i++)
    {
        cout << arr[i] << " ";
    }   
}

int main(){
    int n;
    cout << "No. of elements in the array: " << endl;
    cin >> n;
    int arr[n];
    inputArray(arr, n); 
    bubbleSort(n, arr);
    cout << "Sorted Array: " << endl;
    printArray(arr, n);
    return 0;
}