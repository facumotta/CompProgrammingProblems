#include <bits/stdc++.h>
 
using namespace std;
typedef long long tint;

vector<vector<pair<tint, tint>>> adj;
vector<tint> dist;
vector<bool> processed;

vector<tint> num_min_paths;
vector<tint> length_min_path;
vector<tint> length_max_path;

tint n, m, res;
tint MOD = 1e9+7;
tint INF = 1e18;



void dijkstra(tint x){
    priority_queue<pair<tint,tint>> q;
    //for (tint i = 0; i < n; i++) dist[i] = INF;
    dist[x] = 0; 
    num_min_paths[x] = 1;
    length_min_path[x] = 0;
    length_max_path[x] = 0;

    q.push({0,x});
    while (!q.empty()) {
        tint a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            tint b = u.first, w = u.second;
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                num_min_paths[b] = num_min_paths[a];
                length_min_path[b] = length_min_path[a] + 1;
                length_max_path[b] = length_max_path[a] + 1; 
                q.push({-dist[b],b});

            }else if(dist[a]+w == dist[b]){
                num_min_paths[b] = (num_min_paths[b] + num_min_paths[a])%MOD;
                length_min_path[b] = min(length_min_path[b], length_min_path[a] + 1);
                length_max_path[b] = max(length_max_path[b], length_max_path[a] + 1);                  
            }
        }
    }
}




int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin >> n >> m;
    res = 0;
    adj.resize(n);
    processed.resize(n, false);
    dist.resize(n, INF);
    num_min_paths.resize(n, 0);
    length_min_path.resize(n, INF);
    length_max_path.resize(n, -INF); 
    
    
    for (tint i = 0; i < m; i++) {
        tint from, to, weight;
        cin >> from >> to >> weight;
        from--; to--;
        adj[from].push_back({to, weight});
    }

    dijkstra(0);

    cout << dist[n-1] << " " << num_min_paths[n-1] << " " << length_min_path[n-1] << " " << length_max_path[n-1] << endl;
    
    return 0;
}