// Name: Anish Tilloo
// Roll No. : 34
// Program : Binary Search

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int key){
    if (start <= end) {
      int mid = (start + end)/2;
      if (arr[mid] == key){
        return mid;
      }
      if (arr[mid] > key){
        return binarySearch(arr, start, mid-1, key);
      }
      if (arr[mid] < key){
        return binarySearch(arr, mid+1, end, key);
      }
   }
   return -1;
}

int main(){
    int n, key;
    cout << "Enter the no of elements in the array ";
    cin >> n;
    cout << endl;

    int arr[n];
    cout << "Enter the elements of the array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl;
    cout << "Enter the element you want to search in the array ";
    cin >> key;

    cout << "Binary Search" << endl;
    int index = binarySearch (arr, 0, n-1, key);
    if (index != -1)
    {
        cout << "Element " << key << " found at index " << index << endl;
    }
    else
    {
        cout << "Entered number not found in the array" << endl;
    }
    return 0;
}