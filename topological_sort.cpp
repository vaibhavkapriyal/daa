#include<bits/stdc++.h>

using namespace std;

void DFS1(vector<int> adj[],stack<int> &s,vector<bool> &v,int u)
{
	v[u] = true;
    for (auto i=adj[u].begin();i!=adj[u].end(); i++)
    {
        if (v[*i] == false)
        {
            DFS1(adj,s,v,*i);
        }
    }
    s.push(u);
}

void topo(vector<int> adj[],int V)
{
	int i;
	stack<int> s;
	vector<bool> v(V,false);
	
	for(i=0;i<V;i++)
	{
		if(v[i]==false)
			DFS1(adj,s,v,i);
	}
	
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
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
		adj[u].push_back(v);
	}
	
    topo(adj,V);
    
    return 0;
}
