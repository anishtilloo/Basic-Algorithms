//  Author: Anish Tilloo
//  Roll No. : 34
//  Program: Travelling Salesman Problem

#include <bits/stdc++.h>
using namespace std;

#define INT_MAX 999999
int n;
int** dist;
int TSP(int mask, int pos){
    int VISITED_ALL = (1 << n) - 1;
    if (mask == VISITED_ALL)
    {
        return dist[pos][0];
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if ((mask&(1<<i))==0)
        {
            int newAns = dist[pos][i] + TSP(mask| (1<<i), i);
            ans = min(ans, newAns);
        }
    }
    return ans;
}

int main(){
    cout << "Enter the no of cities: "<< endl;
    cin >> n;
    dist = new int*[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = new int[n];
    }

    cout << "Enter the matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    cout << "Cost is: " << TSP(1, 0) << endl;
    
    
    return 0;
}