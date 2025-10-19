#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;

#define forn(i, n) for(tint i = 0; i < n; i++)

vector<vector<tint>> adj;
vector<bool> visited;
vector<tint> cc;
tint n, m;

void dfs(tint v, tint n_cc){
    visited[v] = true;
    cc[v] = n_cc;

    for(tint u : adj[v]){
        if(!visited[u]){
            dfs(u, n_cc);
        }
    }
}



int main(){
    cin >> n >> m;

    visited.resize(n, false);
    cc.resize(n, -1);
    adj.resize(n, vector<tint>());

    forn(i, m){
        tint a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    

    map<tint, tint> aux;
    tint n_cc = 1;
    forn(i,n){
        if(!visited[i]){
            dfs(i, n_cc);
            aux[n_cc] = i;
            n_cc++;
        }
    }

    tint nucleo = aux[1];
    cout << n_cc-2 << "\n";
    for(auto c:aux){
        if(c.second != nucleo){
            cout << nucleo+1 << " " << c.second+1 << "\n";
        }
    }

    return 0;
}