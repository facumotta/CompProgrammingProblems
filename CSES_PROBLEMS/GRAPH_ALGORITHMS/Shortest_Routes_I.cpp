#include <bits/stdc++.h>
 
using namespace std;
typedef long long tint;
 
tint n, m;
const tint INF = 1e18;
vector<vector<pair<tint, tint>>> adj;
vector<tint> dist;
vector<bool> processed;
 
void dijkstra(tint x){
    priority_queue<pair<tint,tint>> q;
    for (tint i = 0; i < n; i++) dist[i] = INF;
    dist[x] = 0; q.push({0,x});
    while (!q.empty()) {
        tint a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            tint b = u.first, w = u.second;
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b],b});   
            }
        }
    }
}
 
 
int main() {
    cin >> n >> m;
 
    adj.resize(n);
    dist.resize(n);
    processed.resize(n, false);
 
 
    for (tint i = 0; i < m; i++) {
        tint from, to, weight;
        cin >> from >> to >> weight;
        from--; to--;
        adj[from].push_back({to, weight});
    }
 
    dijkstra(0);
 
    for(tint i=0; i<n; i++){
        cout << dist[i] << " ";
    }cout << endl;
 
    return 0;
}