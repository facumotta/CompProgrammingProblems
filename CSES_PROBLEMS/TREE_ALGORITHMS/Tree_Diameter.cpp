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
vpll best_and_depth;
 
const ll INF = 1e9;
 
 
void dfs(ll s, ll d){
 
    visited[s] = true;
    dist[s] = d;
 
    if((adj[s].size() == 1) && (s!= 0) ){
        best_and_depth[s] = {0, d};
        return;
    }
 
    ll depth=-INF;
    ll secondDepth=-INF;
    ll longestPath = -INF;
 
 
    for(auto e: adj[s]){
        if(!visited[e]){
            dfs(e, d+1);
 
            if(depth < secondDepth){
                swap(depth, secondDepth);
            }
            
            secondDepth = max(secondDepth, best_and_depth[e].second);
    
            longestPath = max(longestPath, best_and_depth[e].first);
        }
    }
 
 
    if((depth != -INF) && (secondDepth != -INF)){
        longestPath = max(longestPath, secondDepth - dist[s] + depth - dist[s]);
    }else{
        if(depth != -INF){
            longestPath = max(longestPath, depth - dist[s]);
        }else{
            longestPath = max(longestPath, secondDepth - dist[s]);
        }
    }
 
    best_and_depth[s] = {longestPath, max(depth, secondDepth)};
    return;
}
 
 
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
 
    ll n; cin >> n;
 
    adj.resize(n, vll());
    visited.resize(n, false);
    dist.resize(n, 0);
    best_and_depth.resize(n, {});
 
    for(ll i=0; i<n-1; i++){
       ll a, b; cin >> a >> b;
 
        a--; b--;
 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(0, 0);
 
    // cout << "------------\n";
 
    // for(auto p: best_and_depth){
    //     cout << p.first << " " << p.second << "\n";
    // }
 
 
    if(n == 1) cout << 0;
    else cout << best_and_depth[0].first;
 
 
    return 0;
}