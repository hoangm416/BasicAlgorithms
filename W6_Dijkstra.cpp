//C++ 
#include <bits/stdc++.h> 
using namespace std;

#define INF INT_MAX
#define MAX 100000

vector<pair<int, int>> adj[MAX];

void addEdge(int u, int v, int w) 
{
    adj[u].push_back(make_pair(v, w));
}

int shortestPath(int s, int t, int n) 
{
    priority_queue< pair<int, int>, vector <pair<int, int>> 
        , greater<pair<int, int>> > pq;

    vector<int> dist(n, INF);

    pq.push(make_pair(0, s));
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    if(dist[t] != INF)
        return dist[t];
    else
        return -1;
}

int main() 
{
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u-1, v-1, w);
    }

    int s, t;
    cin >> s >> t;

    cout << shortestPath(s-1, t-1, n);

    return 0;
}

