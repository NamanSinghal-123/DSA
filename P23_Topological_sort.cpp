#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<climits>
using namespace std;
int n=5;
vector<int>d(n);
vector<int>p(n);
vector<int>t1(n);
vector<string>colour(n);
long long int t=0;
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
        cout<<"->"<<i;
        for(auto it:adj[i])
           cout<<it<<" ";
        
        cout<<endl;
      }
    }
};
void dfs_vis(int i,vector<int>adj[])
{
   colour[i]="GRAY";
   t++;
   d[i]=t;
   for(auto it:adj[i])
        {
            if(colour[it]=="WHITE")
            {
                p[it]=i;
                dfs_vis(it,adj);
            }
        }
    cout<<i<<" ";
     colour[i]="BLACK";
     t++;
     t1[i]=t;
}
void DFS(vector<int>adj[])
{
    for(int i=0;i<n;i++)
       {
        colour[i]="WHITE";
        p[i]=0;
       }
    t=0;
    
    for(int i=0;i<n;i++)
      if(colour[i]=="WHITE")dfs_vis(i,adj);
}
int main(void)
{
   
Graph g;
int n=5;
vector<int>adj[n];
g.addEdge(adj, 0, 1);
g.addEdge(adj, 0, 4);
g.addEdge(adj, 1, 2);
g.addEdge(adj, 1, 3);
g.addEdge(adj, 1, 4);
g.addEdge(adj, 2, 3);
g.addEdge(adj, 3, 4);
  cout<<"The topological sort of the graph is : ";
  DFS(adj);
  cout<<endl;
 
}