#include <bits/stdc++.h>

using namespace std;

using ll = int;
using vll = vector<ll>;
using vvll = vector<vll>;

#define cout_vec()


vll color;
vll visited;
vvll adj;



queue<ll> q;

void bfs(){

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        
        for (auto v : adj[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            color[v] = (1 ^ color[u]);
            q.push(v);
        }
    }

}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    ll n; cin >> n;

    color.resize(n,0);
    visited.resize(n,false);
    adj.resize(n,vll());
    
    for(ll i = 1; i<n; i++){
        ll u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(ll i = 0; i<n; i++){
        if(adj[i].size() == 1){
            color[i] = 1;
            q.push(i);
            visited[i] = true;
        }
    }


    bfs();

    ll sum = 0;
    for(auto c:color){
        sum += c;
    }

    cout << min(n-sum, sum);


    return 0;
}