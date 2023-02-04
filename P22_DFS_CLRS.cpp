// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// void addEdge(vector<int> adj[], int u, int v)
// {
// 	adj[u].push_back(v);
// 	adj[v].push_back(u);
// }

// void DFSis(vector<int>adj[],int s,bool visited[]){
//     visited[s]=true;
//     cout<<s<<" ";
//     for(int u: adj[s]){
//         if(visited[u]==false){
//             DFSis(adj,u,visited);
//         }
//     }
// }

// void DFS(vector<int> adj[],int v,int s){
//     bool visited[v];
//     for(int i=0;i<v;i++){
//         visited[i]=false;
//     }
//     DFSis(adj,s,visited);
// }

// int main(){
//     int v,n1,n2;
//     // v=5;
//     v=8;
//     vector<int> adj[v];
//     // addEdge(adj, 0, 1);
//     // addEdge(adj, 0, 2);
//     // addEdge(adj, 1, 3);
//     // addEdge(adj, 2, 3);
//     // addEdge(adj, 1, 4);
//     // addEdge(adj, 3, 4);

//     // DFS(adj,5,0);

//     addEdge(adj,0,1);
//     addEdge(adj,0,4);
//     addEdge(adj,1,2);
//     addEdge(adj,2,5);
//     addEdge(adj,1,4);
//     addEdge(adj,5,1);
//     addEdge(adj,4,5);
//     addEdge(adj,3,0);
//     addEdge(adj,3,4);
//     addEdge(adj,7,3);
//     addEdge(adj,7,6);
//     addEdge(adj,6,3);
//     addEdge(adj,6,7);

//     DFS(adj,8,0);
// }

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<climits>
using namespace std;
int n=8;
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
int n=8;
vector<int>adj[n];
    g.addEdge(adj,0,1);
    g.addEdge(adj,0,4);
    g.addEdge(adj,1,2);
    g.addEdge(adj,2,5);
    g.addEdge(adj,1,4);
    g.addEdge(adj,5,1);
    g.addEdge(adj,4,5);
    g.addEdge(adj,3,0);
    g.addEdge(adj,3,4);
    g.addEdge(adj,7,3);
    g.addEdge(adj,7,6);
    g.addEdge(adj,6,3);
    g.addEdge(adj,6,7);
cout<<" DFS  is : ";
DFS(adj);
cout<<endl;

cout<<"The distance table of the graph is : ";
for(auto it : d)
cout<<it<<" ";
cout<<endl;

cout<<"The predessor table of the graph is : ";
for(auto it: p)
 cout<<it<<" ";
}