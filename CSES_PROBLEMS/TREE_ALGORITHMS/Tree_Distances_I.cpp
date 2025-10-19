#include <bits/stdc++.h>
 
using namespace std;
 
using ll = int;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
 
vvll adj;
 
vll visited;
vll dist;
vpll largest_and_son;
vll parent;
vll ans;
 
const ll INF = 1e9;

 
void dfs(ll s, ll d){
    visited[s] = true;
    dist[s] = d;

    if((adj[s].size() == 1) && (s != 0)){
        largest_and_son[s] = {0, s};
        return;
    }

    ll largest = -INF;
    ll son;
    
    for(auto e:adj[s]){
        if(!visited[e]){
            parent[e] = s;
            dfs(e, d+1);

            if(largest < largest_and_son[e].first + 1){

                largest = largest_and_son[e].first + 1;
                son = e;
            }
        }
    }

    largest_and_son[s] = {largest, son};
    return;
}
 

void bfs(ll s){
    visited[s] = true;

    queue<ll> q;
    q.push(s);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        
        for (auto v : adj[u]) {
            if (visited[v]) continue;
            visited[v] = true;

            ll temp = largest_and_son[v].first;
            ll padre = parent[v];
            
            if(largest_and_son[parent[v]].second != v){
                
            }

            q.push(v);
        }
    }

}


 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
 
    ll n; cin >> n;
 
    adj.resize(n, vll());
    visited.resize(n, false);
    dist.resize(n, 0);
    parent.resize(n);
    largest_and_son.resize(n, {});
 
    for(ll i=0; i<n-1; i++){
       ll a, b; cin >> a >> b;
 
        a--; b--;
 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    parent[0] = 0;

    dfs(0, 0);
 
    cout << "------------\n";
 
    for(auto p: largest_and_son){
        cout << p.first << " " << p.second << "\n";
    }
    

    ans[0] = largest_and_son[0].first;

    // ans[0] = largest_and_son[0];

    // for(ll i=1; i<n; i++){
    //     largest_and_son[i];
    // }


 
 
    return 0;
}