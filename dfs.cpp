#include <bits/stdc++.h>

using namespace std;

void addEdge(vector <int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(vector <int> adj[],int u,bool visited[])
{
	visited[u]=true;
	cout<<u<<" ";
	for(auto it=adj[u].begin();it!=adj[u].end;it++)
	{
		if(!visited[*it])
		{
			dfs(adj,*it,visited);
		}
	}
	/*for(auto v:adj[u])
	{
		if(!visited[*it])
		{
			dfs(adj,v,visited);
		}
	}*/
}
int main()
{
	int V,E;
	cout<<"Enter the no. of vertices of the graph\n";
	cin>>V;
	cout<<"Enter the no. of edges of the graph\n";
	cin>>E;
	vector<int> adj[V];
	bool visited[V];
	for(int i=0;i<E;i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(adj,u,v);
	}
	cout<<"Vertices in dfs traversal";
	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		{
			dfs(adj,i,visited);
		}
	}
	return 0;
}
