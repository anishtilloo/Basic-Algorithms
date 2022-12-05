//  Author: Anish Tilloo
//  Roll No. : 34
//  Program: Insertion Sort

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    int key, j;
    // here we are assuming the first element is already sorted so we are starting the for loop with 1
    for (int i = 1; i < n ; i++)
    {
        key = arr[i];
        j = i - 1;
        // here we are checking if the current element is greater the key 
        // and also checking j is greater than or equal to 0
        // if the above conditions are true then we are incrementing the index og the current element
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        } 
        arr[j + 1] = key;
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
    insertionSort(arr, n);
    cout << "Sorted Array" << endl;
    printArray(arr, n);
    return 0;
}