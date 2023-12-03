//C++ 
#include <bits/stdc++.h> 
using namespace std;
const int N = 100; // maximum number of nodes

void dfs(int n, int m, bool graph[N][N]) 
{
  bool visited[N]; // array to mark the visited nodes
  for (int i = 1; i <= n; i++) 
    visited[i] = false; 

  stack<int> s; // stack to store the nodes to be visited
  for (int i = 1; i <= n; i++) 
  {
    if (!visited[i]) 
    { // if the node is not visited
      s.push(i); // push it to the stack
      while (!s.empty()) 
      {
        int u = s.top(); // get the top node of the stack
        s.pop(); // pop it from the stack
        if (!visited[u]) 
        { // if the node is not visited
          visited[u] = true; // mark it as visited
          cout << u << " ";
          for (int v = n - 1; v >= 0; v--) // for each adjacent node of u in reverse order
          { 
            if (graph[u][v] && !visited[v])  // if it is not visited
              s.push(v); 
          }
        }
      }
    }
  }
}

void solve()
{
    int n, m; // number of nodes and edges
    cin >> n >> m;
    bool graph[N][N]; // adjacency matrix of the graph
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        graph[i][j] = false; // initialize the matrix as false
      }
    }
    for (int i = 0; i < m; i++) {
      int u, v; 
      cin >> u >> v;
      graph[u][v] = true; // mark the edge in the matrix
      graph[v][u] = true; // mark the edge in the matrix (undirected graph)
    }
    dfs(n, m, graph);
}

int main() 
{
  solve(); 
}

