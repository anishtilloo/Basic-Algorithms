#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
    cout << "Enter the no of vertices " << endl;
    cin >> N;
    cout << "Enter the no of edges " << endl;
    cin >> m;
	vector<pair<int,int> > adj[N]; 

	for(int i = 0; i<m ; i++){
		int vex1, vex2, weight;
        cout << "Vertex One: ";
        cin >> vex1;
        cout << "vertex Two: ";
        cin >> vex2;
        cout << "Weight: ";
        cin >> weight;
        cout << endl;
		adj[vex1].push_back(make_pair(vex2,weight));
		adj[vex2].push_back(make_pair(vex1,weight));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
		key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}