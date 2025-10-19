#include <bits/stdc++.h>
 
using namespace std;
 
using ll = int;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll LOGN = log2(1e9)+1;


ll n, q;
vvll bosses;
vll direct;

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
        
        bosses[i][0] = direct[i];
    }

    for(ll j=1; j<LOGN; j++){
        for(ll i=0; i<n; i++){
            bosses[i][j] = bosses[bosses[i][j-1]][j-1];
        }
    }

    return;
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    cin >> n >> q;
    direct.resize(n,0);
    visited.resize(n,false);
    dist.resize(n,0);
    
    adj.resize(n, vll());

    for(ll i=1; i<n; i++){ 
        cin >> direct[i];
        direct[i]--;

        adj[direct[i]].push_back(i);
    }


    dfs(0, 0);


    bosses.resize(n, vll(LOGN));


    precalculation();

    for(ll i=0; i<q; i++){
        ll x, k; cin >> x >> k;

        if(dist[x-1] <= k-1){
            cout << "-1\n";
        }else{
        
            ll ans = x-1;

            

            for(ll p=0; p<LOGN; p++){
                if(k & (1 << p)){
                    ans = bosses[ans][p];
                }
            }

            cout << ans+1 << "\n";
        }
    }
    
    return 0;
}