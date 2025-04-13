#include <bits/stdc++.h>
 
using namespace std;
typedef long long tint;
 
tint n, m, k;
const tint INF = 1e18;
vector<vector<pair<tint, tint>>> adj;
vector<multiset<tint>> dist;
vector<bool> processed;
 
void dijkstra(tint x){
    priority_queue<pair<tint,tint>> q;
    for (tint i = 0; i < n; i++) 
        if(i != x){
            dist[i].insert(INF);
        }
    dist[x].insert(0);
    q.push({0,x});
    while (!q.empty()) {
        tint a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            tint b = u.first, w = u.second;
            for(auto d : dist[a]){
                if(d + w < (*dist[b].rbegin())){
                    if(dist[b].size() <= k-1){
                        dist[b].insert(d+w);
                    }else{
                        dist[b].erase(*dist[b].rbegin());
                        dist[b].insert(d+w);
                    }
                    q.push({-(*dist[b].begin()), b});
                }
            }
        }
    }
}
 
 
int main() {
    cin >> n >> m >> k;
 
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
    cout << dist[n-1].size() << endl;
    for(auto d: dist[n-1]){
        //if(d != INF) 
        cout << d << " ";
    }cout << endl;
 
    return 0;
}