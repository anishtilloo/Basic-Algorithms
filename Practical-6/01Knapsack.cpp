//  Author: Anish Tilloo
//  Roll No. : 34
//  Program: Knapsack Problem

#include<bits/stdc++.h>
using namespace std;

int knapsack(int value[], int wt[], int n, int W){
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] > W)
    {
        return knapsack(value, wt, n - 1, W);
    }
    int maximum = max(knapsack(value, wt, n - 1, W -wt[n - 1]) + value[n - 1], knapsack(value, wt, n - 1, W));
    return maximum;
}

int main(){
    int n, W;
    cout << "Enter the capicity of the knapsack " << endl;
    cin >> W;

    cout << "No of items " << endl;
    cin >> n;

    int value[n];
    int wt[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the weight of that item " << i << " " << endl; 
        cin >> wt[i];
        cout <<  "Enter the value of the items " << i << " " << endl;
        cin >> value[i];
       
    }
    
    cout << knapsack(value, wt, n, W);
    return 0;
}