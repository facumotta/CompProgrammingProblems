#include <bits/stdc++.h>
 
using namespace std;
typedef long long tint;
 
#define forn(i, n) for(tint i = 0; i < n; i++)

tint n, m;
const tint INF = 1e18;
vector<vector<pair<tint, tint>>> adj;
vector<vector<tint>> adjRev;
vector<tint> dist;
vector<bool> processed;
vector<bool> cycle_pos;
vector<bool> visited;

void dfs(tint v){
    visited[v] = true;
    for(auto u : adjRev[v]){
        if(!visited[u]) dfs(u);
    }
}

void bellmanFord(tint x) {
    dist[x] = 0;
    vector<tint> flag_val(n,-INF);

    for (tint i = 1; i <= n+1; i++) {
        if(i==n){
            forn(l, n){
                flag_val[l] = dist[l];
            }
        }
        for (tint u = 0; u < n; u++) {
            for (auto edge : adj[u]) {
                tint v = edge.first;
                tint w = edge.second;
                if (dist[u] != -INF && dist[u] + w > dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    forn(i, n){
        if(dist[i] > flag_val[i]) cycle_pos[i] = true;
    }
}
 
int main() {
    cin >> n >> m;
 
    adj.resize(n);
    adjRev.resize(n);
    dist.resize(n, -INF);
    processed.resize(n, false);
    visited.resize(n, false);
    cycle_pos.resize(n, false);
 
 
    for (tint i = 0; i < m; i++) {
        tint from, to, weight;
        cin >> from >> to >> weight;
        from--; to--;
        adj[from].push_back({to, weight});
        adjRev[to].push_back(from);
    }

    bellmanFord(0);

    dfs(n-1);
    
    forn(i, n){
        if(visited[i] && cycle_pos[i]){
            cout << "-1\n";
            return 0;
        }
    }
    cout << dist[n-1] << "\n";
    
    return 0;
}