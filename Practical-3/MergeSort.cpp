//  Author: Anish Tilloo
//  Roll No. : 34
//  Program: Merge Sort

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    // size of array one and array two
    int arrayOne = mid - left + 1;
    int arrayTwo = right - mid;

    // dynamicall allocating two sub array
    auto *subArrayOne = new int[arrayOne];
    auto *subArrayTwo = new int[arrayTwo];

    // putting the elements of array one and two from main array
    for (int i = 0; i < arrayOne; i++)
    {
        subArrayOne[i] = arr[left + i];
    }
    for (int j = 0; j < arrayTwo; j++)
    {
        subArrayTwo[j] = arr[mid + 1 + j];
    }

    int indexOfOne = 0;
    int indexOfTwo = 0;
    int indexOfMerged = left;

    // merging the arrays 
    while (indexOfOne < arrayOne && indexOfTwo < arrayTwo)
    {
        if (subArrayOne[indexOfOne] <= subArrayTwo[indexOfTwo])
        {
            arr[indexOfMerged] = subArrayOne[indexOfOne];
            indexOfOne++;
        }
        else
        {
            arr[indexOfMerged] = subArrayTwo[indexOfTwo];
            indexOfTwo++;
        }
        indexOfMerged++; 
    }

    // if one array end the copy all the remaining elements from the remaining array
    while (indexOfOne < arrayOne)
    {
        arr[indexOfMerged] = subArrayOne[indexOfOne];
        indexOfOne++;
        indexOfMerged++;
    }
    
    while (indexOfTwo < arrayTwo)
    {
        arr[indexOfMerged] = subArrayTwo[indexOfTwo];
        indexOfTwo++;
        indexOfMerged++;
    } 
}

void mergeSort(int arr[], int left, int right){
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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
    int arraySize;
    cout << "Enter the size of the array " << endl;
    cin >> arraySize;

    int arr[arraySize];
    inputArray(arr, arraySize);
     
    mergeSort(arr, 0, arraySize - 1);

    cout << "Sorted Array" << endl;
    printArray(arr, arraySize);
}