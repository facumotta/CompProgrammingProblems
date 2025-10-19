#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;

#define forn(i, n) for(tint i = 0; i < n; i++)

vector<vector<tint>> adj;
vector<tint> visited;
vector<tint> parent;
tint n, m;
tint foundCycle;
tint start_cycle, end_cycle;

bool dfs(tint v){
    visited[v] = 1;
    
    for(auto u : adj[v]){
        if(visited[u] == 2) continue;

        if(visited[u] == 1){
            foundCycle = true;
            start_cycle = u;
            end_cycle = v;
            return true;
        }

        parent[u] = v;
        if(dfs(u)){
            return true;
        }
    }

    visited[v] = 2;
    return false;
}


int main(){
    cin >> n >> m;

    visited.resize(n, 0);
    parent.resize(n, -1);
    adj.resize(n, vector<tint>());
    foundCycle = false;
    start_cycle = -1;


    forn(i, m){
        tint a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    
    forn(i, n){
        if(visited[i] == 0 && dfs(i)){
            break;
        }
    }


    if(!foundCycle){
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

        reverse(trip.begin(), trip.end());
        cout << nVertex+1 << "\n";
        for(auto v: trip){
            cout << v+1 << " ";
        }cout << trip[0]+1 << "\n";
    }
    return 0;
}