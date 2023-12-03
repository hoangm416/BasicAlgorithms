//C++
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
pair<long long, pair<int, int> > p[MAX];

int root(int x, int id[]) 
{
    while(id[x] != x) {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y, int id[]) 
{
    int p = root(x, id);
    int q = root(y, id);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[], int edges, int id[]) {
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0; i < edges; ++i) 
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x, id) != root(y, id)) {
            minimumCost += cost;
            union1(x, y, id);
        }    
    }
    return minimumCost;
}

int main() 
{
    int nodes, edges, u, v, w;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0; i < edges; i++) {
        cin >> u >> v >> w;
        p[i] = make_pair(w, make_pair(u, v));
    }
    sort(p, p + edges);
    int id[MAX];
    for(int i = 0; i < MAX; i++)
        id[i] = i;
    minimumCost = kruskal(p, edges, id);
    cout << minimumCost << endl;
    return 0;
}

