//  Author: Anish Tilloo
//  Roll No. : 34
//  Program: Selection Sort

#include <bits/stdc++.h>
using namespace std;

// Selection Sort
void selectionSort(int arr[], int n){
    // iterating from 1st to 2nd last element 
    for (int i = 0; i < n - 1; i++)
    {
        // iterating from 2nd element last element
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[i], arr[j]);   
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
    cout << "Enter the size of the array " << endl;
    cin >> n;
    int arr[n];
    inputArray(arr, n);
    selectionSort(arr, n);
    cout << "Sorted Array: " << endl;
    printArray(arr, n);
    return 0;
}