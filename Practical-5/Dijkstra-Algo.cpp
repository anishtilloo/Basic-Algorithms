//  Author: Anish Tilloo
//  Roll No. : 34
//  Program: Dijkstra Algorithm

#include <bits/stdc++.h>
using namespace std;

// Dijkstra Algorithm
class Graph{
    public:
    int V;
    list<pair<int, int> > *l;
    Graph(int v){
        V = v;
        l = new list<pair<int, int> > [V];
    }

    void addEdge(int ver1, int ver2, int wt, bool undirected = true){
        l[ver1].push_back({wt, ver2});
        if (undirected)
        {
            l[ver2].push_back({wt, ver1});
        }
    }

    int dijkstra(int source, int destination){

        // dist array
        vector<int> dist(V, INT_MAX);
        // set of pair to store wt and node
        set<pair<int, int> > s;
        
        // initialize the distance
        dist[source] = 0;
        s.insert({0, source});
        

        // check if the set is empty or not 
        while (!s.empty())
        {
            // see what is at the first position in the set
            auto atFirst = s.begin();
            // actual node 
            auto node  = atFirst->second;
            // dist of the node covered till now
            auto distTillNow = atFirst->first;

            // pop the first value
            s.erase(atFirst);

            for(auto nbrPair : l[node]){
                // neighbour node 
                auto nbr = nbrPair.second;
                // weight of the current edge you are in or want to pass
                auto currentEdge = nbrPair.first;

                if (distTillNow + currentEdge < dist[nbr])
                {
                    auto ifExist = s.find({dist[nbr], nbr});
                    if (ifExist != s.end())
                    {
                        s.erase(ifExist);
                    }
                    

                    dist[nbr] = distTillNow + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
                
            }
        }
        for (int i = 0; i < V; i++)
        {
            cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
        }
        return dist[destination];
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
        int vex1, vex2, weight;
        cout << "Vertex One: ";
        cin >> vex1;
        cout << "vertex Two: ";
        cin >> vex2;
        cout << "Weight: ";
        cin >> weight;
        cout << endl;

        g.addEdge(vex1, vex2, weight);
    }
    cout << endl;

    int src, dest;
    cout << "Enter the source node: " << endl;
    cin >> src;
    cout << "Enter the distnation node: " << endl;
    cin >> dest;

    g.dijkstra(src, dest);

    return 0;
}