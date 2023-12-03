//C++ 
#include <bits/stdc++.h> 
using namespace std;
 
#define V 10000

int rGraph[V][V];
/* Returns true if there is a path from source 's' to sink
  't' in residual graph. Also fills parent[] to store the
  path */
bool bfs(int s, int t, int parent[], int n)
{
    // Create a visited array and mark all vertices as not
    // visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    // Create a queue, enqueue source vertex and mark source
    // vertex as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 1; v <= n; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                // If we find a connection to the sink node,
                // then there is no point in BFS anymore We
                // just have to set its parent and can return
                // true
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // We didn't reach sink in BFS starting from source, so
    // return false
    return false;
}
 
// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int s, int t, int n) 
{
    int u, v;
    int parent[n];
    int max_flow = 0;

    while (bfs(s, t, parent, n)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;

    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        rGraph[u][v] = c;
    }

    cout << fordFulkerson(s, t, n);

    return 0;
}

