// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// void addEdge(vector<int> adj[], int u, int v)
// {
//   adj[u].push_back(v);
//   adj[v].push_back(u);
// }

// void printGraph(vector<int> adj[], int V)
// {
//   for (int v = 0; v < V; ++v)
//   {
//     cout << "\n Adjacency list of vertex " << v << "\n head ";
//     for (auto x : adj[v])
//       cout << "-> " << x;
//     printf("\n");
//   }
// }

// void BFS_CLRS(vector<int> G[], int source, int n)
// {
//   vector<string> colour(n, "white");
//   vector<int> distance(n, 1000000);
//   vector<int> parent(n, -1);

//   colour[source] = "gray";
//   distance[source] = 0;

//   queue<int> q;
//   q.push(source);

//   while (!q.empty())
//   {
//     int u = q.front();
//     q.pop();

//     cout << u << " ";

//     for (auto v = G[u].begin(); v != G[u].end(); v++)
//     {
//       if (colour[*v] == "white")
//       {
//         colour[*v] = "grey";
//         distance[*v] = distance[u] + 1;
//         parent[*v] = u;

//         q.push(*v);
//       }
//     }

//     colour[u] = "black";
//   }
// }
// int main()
// {
//   // int V = 8;
//   int V = 8, n1, n2;
//   // cout<<"Enter the number of edges"<<endl;
//   // cin>>V;
//   vector<int> adj[V];
//   addEdge(adj, 0, 1);
//   addEdge(adj, 0, 3);
//   addEdge(adj, 1, 2);
//   addEdge(adj, 3, 4);
//   addEdge(adj, 3, 6);
//   addEdge(adj, 4, 5);
//   addEdge(adj, 6, 7);
//   addEdge(adj, 4, 6);
//   addEdge(adj, 5, 7);
//   // cout<<"Enter n1 as node and n2 as its one of the connected vertex.."<<endl;
//   // for(int i=0;i<V+1;i++){
//   //   cin>>n1>>n2;
//   //   addEdge(adj,n1,n2);
//   // }
//   BFS_CLRS(adj, 0, V);
//   // 0 1 3 2 4 6 5 7
//   // printGraph(adj, V);
//   return 0;
// }
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
class Graph
{
    public:
    void addEdge(vector<int>adj[],int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print(vector<int>adj[],int n)
    {
        for(int i=0;i<n;++i)
        {
            cout<<i<<"->";
            for(auto it:adj[i])
               cout<<it<<" ";
            cout<<endl;
        }
    }
};
void bfs(vector<int>adj[],vector<int>&d,vector<int>&p,int v,int s)
{
    vector<string>colour(v);
    for(int i=1;i<v;++i)
    {
        d[i]=INT16_MAX;
        p[i]=0;
        colour[i]="WHITE";
    }
    colour[s]="GRAY";
    d[s]=0;
    p[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        int x=q.front();
        q.pop();
        for(auto it:adj[x])
        {
            if(colour[it]=="WHITE")
            {
                  colour[it]="GRAY";
                  d[it]=d[x]+1;
                  p[it]=x;
                 q.push(it);
            }
         colour[it]="BLACK";
        }
    }
}
int main(void)
{
  Graph g;
//   int n=5;
int n=8;
  vector<int>adj[n];
//   g.addEdge(adj, 0, 1);
//   g.addEdge(adj, 0, 4);
//   g.addEdge(adj, 1, 2);
//   g.addEdge(adj, 1, 3);
//   g.addEdge(adj, 1, 4);
//   g.addEdge(adj, 2, 3);
//   g.addEdge(adj, 3, 4);
    g.addEdge(adj, 0, 1);
	g.addEdge(adj, 0, 3);
	g.addEdge(adj, 1, 2);
	g.addEdge(adj, 3, 4);
	g.addEdge(adj, 3, 6);
	g.addEdge(adj, 4, 5);
	g.addEdge(adj, 6, 7);
    g.addEdge(adj, 4, 6);
    g.addEdge(adj, 5, 7);
  vector<int>d(n);
  vector<int>p(n);
  cout<<"The adjacency list represetation of the graph is : \n";
  g.print(adj,n);
  int s=0;
  cout<<"The bfs of the graph is : \n";
  bfs(adj,d,p,n,s);
  cout<<endl;
  cout<<"The distance respectively is : \n";
  cout<<"d"<<" ";
  for(auto it:d)
    cout<<it<<" ";
    cout<<endl;
  cout<<"The predecssor of the graph is \n";
  cout<<"p"<<" ";
   for(auto it:p)
    cout<<it<<" ";
}