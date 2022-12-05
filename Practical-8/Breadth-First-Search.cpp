//  Author: Anish Tilloo
//  Roll No. : 34
//  Program: Breadth First Search

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

    void bfs(int source){
        queue<int> q;
        bool *visited = new bool[V]{0};

        // We are pushing the source node inside queue
        // and it is also visited
        q.push(source);
        visited[source] = true;

        // if the queue is not empty then pop out the node and print it 
        // and insert its neighbours into the queue
        while (!q.empty())
        {
            int f = q.front();
            cout << f << " ";
            q.pop();

            // push the neighbours of the current node if they are not already visited
            for(auto nbr : l[f]){
                if (!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }  
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
    cout << "BFS" <<endl;
    g.bfs(s);
    
    return 0;
}