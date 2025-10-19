#include<bits/stdc++.h>
using namespace std;
 
typedef long long tint;
 
vector<vector<tint>> adj;
 
vector<tint> paths;
 
tint MOD = 998244353;
 
vector<bool> visited;
vector<tint> dist; 
vector<vector<tint>> estados;
 
tint N, M, K;
tint d;
 
void bfs(tint s){
    visited[s] = true;
    dist[s]=0;
    queue<tint> q;
    q.push(s);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (visited[v]) continue;
            dist[v] = dist[u] + 1;
            visited[v] = true;
            q.push(v);
        }
    }
}
 
 
 
 
tint dp(tint bol, tint caj){
 
    if(caj == 1){
        if(bol > K-1){
            return 0;
        }else{
            return 1;
        }
    }
 
    if(bol == 0){
        return 1;
    }
 
    if(estados[bol][caj] != -1){
        return estados[bol][caj];
    }else{
 
        estados[bol][caj] = 0;
        for(tint i=0; i<=min(K-1, bol); i++){
            estados[bol][caj] += dp(max((tint) 0,bol-i),caj-1);
            estados[bol][caj] = estados[bol][caj]%MOD;
        }
 
 
        return estados[bol][caj];
    }
 
}
 
 
 
 
void solve(){
    bfs(0);
 
    if(dist[1]%K == 0) d = dist[1]/K;
    else d= dist[1]/ K + 1;
 
 
    // cout << "dias que tienen que pasar: " << d << "\n";
    estados.resize((d+1)*K, vector<tint>(d+1, -1));
 
    paths[0] = 1;
 
    tint formas = 0;
    tint total  = 0;
    vector<tint> temp;
    for(tint steps = 0; steps < d*K; steps++){
 
        temp = paths;
        paths.assign(N, 0);
 
        for(tint u = 0; u<N; u++){
            for(auto v:adj[u]){
                // arista u - v
                paths[v] += temp[u];
                paths[v] = paths[v]%MOD;
            }
        }
 
        formas = 0;
        // K =2
        if(paths[1] != 0){
            formas = dp(max((tint) 0, steps+1-d), d);
        }
 
        // cout << "cant de formas de llegar con " << steps+1 << " pasos es: " << formas << "\n";
        // cout << "cantidad de caminos a 1 sin importar orden: " << paths[1] << "\n"; 
        // cout << "-------------\n";
 
        total += ((formas * paths[1]) %MOD);
 
        total = total%MOD;
    }
 
    cout << total << "\n";
 
    return;
}
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
 
    adj.resize(N);
    paths.resize(N);
    visited.resize(N, false);
    dist.resize(N, 0);
 
 
    for(int i=0; i<M; i++){
        tint u,v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
 
 
    solve();
 
 
    return 0;
}