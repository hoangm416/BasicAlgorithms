//C++ 
#include <bits/stdc++.h> 
using namespace std;
const int N = 10; // maximum number of nodes

// function to check if a vertex can be added to the cycle
bool isSafe(int v, bool graph[N][N], int path[], int pos) 
{
  // check if v is adjacent to the previous vertex
  if (graph[path[pos - 1]][v] == 0) 
    return false;

  // check if v is already in the path
  for (int i = 0; i < pos; i++) {
    if (path[i] == v) 
      return false;
  }
  return true;
}

// function to find a Hamiltonian cycle using backtracking
bool hamCycleUtil(bool graph[N][N], int path[], int pos, int n) 
{
  // base case: if all vertices are in the path
  if (pos == n) 
  {
    // check if there is an edge from the last vertex to the first vertex
    if (graph[path[pos - 1]][path[0]] == 1) 
      return true; // cycle found
    else 
      return false; // cycle not found
  }
  // try different vertices as the next candidate
  for (int v = 1; v < N; v++) 
  {
    // check if v can be added to the path
    if (isSafe(v, graph, path, pos)) {
      path[pos] = v; // add v to the path
      // recur to find the rest of the path
      if (hamCycleUtil(graph, path, pos + 1, n)) {
        return true; // cycle found
      }
      path[pos] = -1; // backtrack and remove v from the path
    }
  }
  return false; // no cycle found
}

// function to check if a graph is Hamiltonian and print the result
bool hamCycle(bool graph[N][N], int n)
{
  int *path = new int[n+1]; // array to store the path
  for (int i = 0; i < n; i++) 
    path[i] = -1; // initialize the path as empty

  path[0] = 1; // start from vertex 1
  // call the utility function to find a cycle
  if (hamCycleUtil(graph, path, 1, n) == false) {
    cout << "0\n"; // no cycle found
    delete[] path;
    return false;
  }
  cout << "1\n"; // cycle found
  delete[] path;
  return true;
}

// function to read the input and call hamCycle for each graph
void solve() 
{
  int T; // number of graphs
  cin >> T;
  while (T--) 
  {
    int n, m; // number of nodes and edges
    cin >> n >> m;
    bool graph[N][N]; // adjacency matrix of the graph
    for (int i = 0; i < N; i++) 
      for (int j = 0; j < N; j++) 
        graph[i][j] = false; // initialize the matrix as empty
      
    for (int i = 0; i < m; i++) {
      int u, v; // endpoints of an edge
      cin >> u >> v;
      graph[u][v] = true; // mark the edge in the matrix
      graph[v][u] = true; // mark the edge in the matrix (undirected graph)
    }
    hamCycle(graph, n); // check if the graph is Hamiltonian and print the result
  }
}

int main() 
{
  solve(); 
}

