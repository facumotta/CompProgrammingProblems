#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;

#define forn(i, n) for(tint i = 0; i < n; i++)

vector<vector<tint>> adj;
vector<bool> visited;
vector<tint> parent;
tint n, m;
tint start_cycle, end_cycle;

bool dfs(tint v, tint par){
    visited[v] = true;
    
    for(auto u : adj[v]){
        if(u == par) continue;

        if(visited[u]){
            start_cycle = u;
            end_cycle = v;
            return true;
        }

        parent[u] = v;
        if(dfs(u, parent[u])){
            return true;
        }
    }

    return false;
}


int main(){
    cin >> n >> m;

    visited.resize(n, false);
    parent.resize(n, -1);
    adj.resize(n, vector<tint>());
    start_cycle = -1;


    forn(i, m){
        tint a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    forn(i, n){
        if(!visited[i] && dfs(i, parent[i])){
            break;
        }
    }


    if(start_cycle == -1){
        cout << "IMPOSSIBLE\n";
    }else{
        vector<tint> trip;
        tint next_vertex = end_cycle;
        trip.push_back(next_vertex);
        tint nVertex = 1;
    
        while(next_vertex != start_cycle){
            nVertex++;
            next_vertex = parent[next_vertex];
            trip.push_back(next_vertex);
        }

        cout << nVertex+1 << "\n";
        for(auto v: trip){
            cout << v+1 << " ";
        }cout << trip[0]+1 << "\n";
    }
    return 0;
}