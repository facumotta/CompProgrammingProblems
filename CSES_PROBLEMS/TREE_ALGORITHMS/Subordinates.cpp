#include <bits/stdc++.h>

using namespace std;

using ll = int;
using vll = vector<ll>;
using vvll = vector<vll>;

vll ans;
vll visited;
vvll adj;

void dfs(ll s){
    visited[s] = true;

    for(auto e:adj[s]){
        if(!visited[e]){
            dfs(e);
        }
        ans[s] += 1 + ans[e];
    }


}


int main(){
    ll n; cin >> n;

    ans.resize(n,0);
    visited.resize(n,false);
    adj.resize(n,vll());
    
    for(ll i = 1; i<n; i++){
        ll v; cin >> v;
        adj[v-1].push_back(i);
    }


    dfs(0);


    for(auto a:ans){
        cout << a << " ";
    }


    return 0;
}