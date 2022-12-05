#include <bits/stdc++.h>
using namespace std;

void linearSearch(int arr[], int n, int key){
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element " << key << " found at index " << i << endl;
            flag = true;
        } 
    }
    if (flag = false)
    {
        cout << "Element Not Found" << endl;
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

    cout << "Linear Search" << endl;
    linearSearch(arr, n, key);

    return 0;
}