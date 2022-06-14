#include <bits/stdc++.h>
#define pb push_back
  
using namespace std;
  
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
  
void bfs(int u,vector<int> adj[],vector<bool> &v)
{
    queue<int> q;
  
    q.push(u);
    v[u] = true;
  
    while (!q.empty()) {
  
        int f = q.front();
        q.pop();
  
        cout << f << " ";
  
        // Enqueue all adjacent of f and mark them visited 
        for (auto i = adj[f].begin(); i != adj[f].end(); i++) {
            if (!v[*i]) {
                q.push(*i);
                v[*i] = true;
            }
        }
    }
}
  
// Driver code
int main()
{
    int V,E;
	cout<<"Enter the no. of vertices of the graph\n";
	cin>>V;
	cout<<"Enter the no. of edges of the graph\n";
	cin>>E;
	vector<int> adj[V];
	for(int i=0;i<E;i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(adj,u,v);
	}
  	
  	vector<bool> v(V,false);
  	
    for (int i = 0; i < V; i++) {
        if (!v[i])
            bfs(i,adj,v);
    }
  
    return 0;
}