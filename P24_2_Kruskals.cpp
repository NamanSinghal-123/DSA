// #include <bits/stdc++.h>
// using namespace std;

// struct Edge
// {
//   int src, dest, wt;
//   Edge(int s, int d, int w)
//   {
//     src = s;
//     dest = d;
//     wt = w;
//   }
// };

// bool cmp(Edge e1, Edge e2)
// {
//   return e1.wt < e2.wt;
// }

// int ffind(int parent[], int x)
// {
//   if (parent[x] == x)
//     return x;
//   parent[x] = ffind(parent, parent[x]);
//   return parent[x];
// }

// void union_(int parent[], int rank[], int x, int y)
// {
//   int x_rep = ffind(parent, x), y_rep = ffind(parent, y);
//   if (x_rep == y_rep)
//   {
//     return;
//   }

//   if (rank[x_rep] < rank[y_rep])
//     parent[x_rep] = y_rep;
//   else if (rank[y_rep] < rank[x_rep])
//     parent[y_rep] = x_rep;
//   else
//   {
//     parent[y_rep] = x_rep;
//     rank[x_rep]++;
//   }
// }
// int kruskal(Edge arr[], int v)
// {
//   int parent[v];
//   int rank[v];
//   for (int i = 0; i < v; i++)
//   {
//     parent[i] = i;
//     rank[i] = 0;
//   }
//   sort(arr, arr + v, cmp);
//   int res = 0;

//   for (int i = 0, s = 0; s < v - 1; i++)
//   {
//     Edge e = arr[i];
//     int x = ffind(parent, e.src);
//     int y = ffind(parent, e.dest);
//     if (x != y)
//     {
//       res += e.wt;
//       union_(parent, rank, x, y);
//       s++;
//     }
//   }
//   return res;
// }
// int main()
// {
//   int v = 5;

//   Edge arr[] = {Edge(0, 1, 10), Edge(0, 2, 8), Edge(1, 2, 5), Edge(1, 3, 3), Edge(2, 3, 4), Edge(2, 4, 12), Edge(3, 4, 15)};
//   // cout << arr[5].wt << arr[5].src << arr[5].dest << endl;
//   cout << "The cost of MST of graph is : " << kruskal(arr, 5);
//   return 0;
// }


 
#include <bits/stdc++.h>
using namespace std;
 
// Disjoint_Set data structure
// path compression + rank by union
 
class Disjoint_Set {
    int* parent;
    int* rank;
 
public:
    Disjoint_Set(int n)
    {
        parent = new int[n];
        rank = new int[n];
 
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
 
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = find(parent[i]);
    }
 
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
 
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};
 
class Graph {
    vector<vector<int> > edgelist;
    int V;
 
public:
    Graph(int V) { this->V = V; }
 
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({ w, x, y });
    }
 
    void kruskals_mst()
    {
        sort(edgelist.begin(), edgelist.end());
 
        Disjoint_Set s(V);
        int ans = 0;
        cout << "Following are the edges in the "
                "constructed MST"
             << endl;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
 
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
                cout << x << " -- " << y << " =weight:" << w
                     << endl;
            }
        }
 
        cout << "Minimum Cost Spanning Tree: " << ans;
    }
};
 
// Driver's code
int main()
{
    
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
 
    g.kruskals_mst();
    return 0;
}