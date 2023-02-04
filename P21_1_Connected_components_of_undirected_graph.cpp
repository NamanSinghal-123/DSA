#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void BFS_CLRS(vector<int> adj[],int v, int source,bool visited[]){
    queue<int> q;
    visited[source]=true;
    cout<<"\nsource is:"<<source<<endl;
    q.push(source);
    
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v: adj[u]){
            if(visited[v]==false){
                visited[v]=true;
                q.push(v);
            }
        }
    }

}

int BFSDis(vector<int>adj[],int v){
    bool visited[v+1];
    int count=0;
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            BFS_CLRS(adj,v,i,visited);
            count++;
        }
    }
    return count;
}

int main(){
    int V=8, n1, n2;
    // cout << "Enter the number of edges" << endl;
    // cin >> V;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
	// addEdge(adj, 0, 3);
	addEdge(adj, 1, 2);
	addEdge(adj, 3, 4);
	addEdge(adj, 3, 6);
	addEdge(adj, 4, 5);
	addEdge(adj, 6, 7);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 7);
    int k=BFSDis(adj,V);
    cout<<"\nThe number of connected components are "<<k;
}
