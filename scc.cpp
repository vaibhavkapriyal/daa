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

void DFS2(vector<int> adj[],vector<bool> &v,int u)
{
	cout<<u<<" ";
	v[u] = true;
    for (auto i=adj[u].begin();i!=adj[u].end(); i++)
    {
        if (v[*i] == false)
        {
            DFS2(adj,v,*i);
        }
    }
	
}

void findSCC(vector<int> adj1[],vector<int> adj2[],int V)
{
	int i;
	stack<int> s;
	vector<bool> v(V,false);
	
	for(i=0;i<V;i++)
	{
		if(v[i]==false)
			DFS1(adj1,s,v,i);
	}
	
	for(i=0;i<V;i++)
	{
		v[i]=false;
	}
	cout<<"Strongly Connected Components : \n";
	while(!s.empty())
	{
		int c=s.top();
		s.pop();
		
		if(v[c]==false)
		{
			DFS2(adj2,v,c);
			cout<<"\n";
		}
	}
}

int main()
{
	int V,E;
	cout<<"Enter the no. of vertices of the graph\n";
	cin>>V;
	cout<<"Enter the no. of edges of the graph\n";
	cin>>E;
	vector<int> adj1[V];
	vector<int> adj2[V];
	for(int i=0;i<E;i++)
	{
		int u,v;
		cin>>u>>v;
		adj1[u].push_back(v);
		adj2[v].push_back(u);
	}
	
    findSCC(adj1,adj2,V);
    
    return 0;
}