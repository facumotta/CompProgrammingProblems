#include <bits/stdc++.h>
 
using namespace std;
typedef long long tint;
 
#define forn(i, n) for(tint i = 0; i < n; i++)

tint n, m;
tint INF = 1e18;
vector<vector<pair<tint, tint>>> adj;
vector<tint> dist;
vector<tint> parent;

void bellmanFord(tint k) {
    dist[k] = 0;

    tint x;
    for (tint i = 0; i <= n+2; i++) {
        x = -1;
        for (tint u = 0; u < n+1; u++) {
            for (auto edge : adj[u]) {
                tint v = edge.first;
                tint w = edge.second;
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = max(-INF, dist[u] + w);
                    parent[v] = u;
                    x = v;
                }
            }
        }
    }

    if(x != -1){
        tint y = x;
        forn(i, n) y = parent[y];

        tint current = parent[y];
        vector<tint> path;
        path.push_back(y);
        while(current != y && path.size() >= 1){
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(current);

        reverse(path.begin(), path.end());

        cout << "YES\n";
        forn(i, path.size()){
            cout << path[i]+1 << " ";
        }
    }else{
        cout << "NO\n";
    }
    return;
}
 
int main() {
    cin >> n >> m;
 
    adj.resize(n+1);
    dist.resize(n+1, INF);
    parent.resize(n+1, -1); 

    for (tint i = 0; i < m; i++) {
        tint from, to, weight;
        cin >> from >> to >> weight;
        from--; to--;
        adj[from].push_back({to, weight});
    }

    forn(i, n){
        adj[n].push_back({i, 0});
    }

    bellmanFord(n);

    return 0;
}