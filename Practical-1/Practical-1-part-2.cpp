#include <bits/stdc++.h>
using namespace std;


// Iterative Approach

void binarySearch(int arr[], int n, int key){
    int start = 0;
    int end = n - 1;
    // This function takes the starting value and the ending value
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    while (start <= end){
        int mid = (start + end)/2;
        if (arr[mid] == key)
        {
            cout << "Element found at index " << mid << endl;
            break;
        }
        else if (arr[mid] < key)
        {
            start =  mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            cout << "Element not found" << endl;
        } 
    }
}

int main(){
    int n, key;
    cout << "Enter the no of elements in the array ";
    cin >> n;
    cout << endl;
    
    int arr[n];
    cout << "Enter the elemnts of the array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl;
    cout << "Enter the element you want to search in the array ";
    cin >> key;

    cout << "Binary Search" << endl;
    binarySearch(arr, n, key);

    return 0;
}
