#include<bits/stdc++.h>
using namespace std;
 
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
void DFS(int u, vector<int> adj[],vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    for (auto i=adj[u].begin();i!=adj[u].end(); i++)
    {
        if (visited[*i] == false)
        {
            DFS(*i, adj, visited);
        }
    }
    /*
    for(i=0;i<adj[u].size();i++)
    {
    	if(visited[adj[u][i]]==false)
    	{
    		DFS(adj[u][i],adj,visited);
    	}
    }
    */
}

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
    
    for(int i=0;i<V;i++)
    {
    	if(v[i]==false)
    		DFS(i,adj,v);
    }
    return 0;
}
