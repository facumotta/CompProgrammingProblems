#include <bits/stdc++.h>
 
using namespace std;
 
using ll = int;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll LOGN = log2(1e9)+1;


ll n, q;
vvll up;
vll parent;

vvll adj;

vector<bool> visited;
vll dist;

void dfs(ll s, ll d){
    visited[s] = true;
    dist[s] = d;

    for(auto n:adj[s]){
        if(!visited[n]){
            dfs(n, d+1);
        }
    }

    return;
}


void precalculation(){

    for(ll i=0; i<n; i++){
        
        up[i][0] = parent[i];
    }

    for(ll j=1; j<LOGN; j++){
        for(ll i=0; i<n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    return;
}

ll get_lca(ll a, ll b){
    if(dist[a] < dist[b]){
        swap(a, b);
    }

    ll k = dist[a]- dist[b]; 

    for(int i=LOGN-1; i>=0; i--){
        if(k & (1 << i)){
            a = up[a][i];
        }
    }

    if(a == b) return a;

    for(int i=LOGN-1; i>=0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    cin >> n >> q;
    parent.resize(n,0);
    visited.resize(n,false);
    dist.resize(n,0);
    
    adj.resize(n, vll());

 for(ll i=1; i<n; i++){ 
        cin >> parent[i];
        parent[i]--;

        adj[parent[i]].push_back(i);
    }


    dfs(0, 0);


    up.resize(n, vll(LOGN));


    precalculation();

    for(ll i=0; i<q; i++){
        ll a, b; cin >> a >> b;

        a--; b--;

        cout << get_lca(a, b)+1 << "\n";

    }
    
    return 0;
}