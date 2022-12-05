//  Author: Anish Tilloo
//  Roll No. : 34
//  Program: Depth First Search

#include <bits/stdc++.h>
using namespace std;


// Creating a graph using Adjencency List(Array of List)
class Graph{
    public:
    int V;
    // pointer to an array of list 
    list<int> *l;

    // we are creating a graph constructor 
    // where we will take how many vertices 
    // this graph will have
    Graph(int v){
        V = v;
        // Dynamically creating a new List of size Vertices
        // creating Vertices no of linked list
        l = new list<int>[V];
    }

    void addEdge(int ver1, int ver2, bool undirected = true){
        l[ver1].push_back(ver2);
        if (undirected)
        {
            l[ver2].push_back(ver1);
        }
    }

    void printGraph(){
        // Iterating over all rows
        for (int i = 0; i < V; i++)
        {
            cout << i << "->";
            // Iterating over every element in the linked list
            for(auto node : l[i]){
                cout << node << ",";
            }
            cout << endl;
        }
        
    }

    void dfsHelper(int node, bool *visited){
      visited[node] = true;
      cout << node << ",";
      // make a dfs call on all its unvisited neighbours
      for(auto nbr : l[node]){
        if (!visited[nbr])
        {
            dfsHelper(nbr, visited);
        }
      }
      return;
    }

    void dfs(int source){
        bool *visited = new bool [V]{0};
        dfsHelper(source, visited);
    }

};


int main(){
    int n;
    cout << "Enter the number of vertices" << endl;
    cin >> n;
    Graph g(n);
    int m;
    cout << "Enter the no of edges" << endl;
    cin >> m;
    cout << endl;

    cout <<  "Edges " << endl;
    for (int i = 0; i < m; i++)
    {
        int vex1, vex2;
        cout << "Vertex One: ";
        cin >> vex1;
        cout << "vertex Two: ";
        cin >> vex2;
        cout << endl;

        g.addEdge(vex1, vex2);
    }
    cout << endl;

    g.printGraph();

    int s;
    cout << "Enter the source Node " << endl;
    cin >> s;
    cout << "DFS" <<endl;
    g.dfs(s);
    
    return 0;
}