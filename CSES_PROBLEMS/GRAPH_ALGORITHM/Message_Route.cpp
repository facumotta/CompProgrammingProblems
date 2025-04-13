#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;

#define forn(i, n) for(tint i = 0; i < n; i++)

vector<vector<tint>> adj;
vector<bool> visited;
vector<tint> parent;
tint n, m;

void bfs(int s) {
    visited[s] = true;
    parent[s] = -1;
    
    queue<int> q;
    q.push(s);
    
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        
        for (auto v : adj[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            parent[v] = u;
            q.push(v);
        }
    }
}


int main(){
    cin >> n >> m;

    visited.resize(n, false);
    parent.resize(n, -1);
    adj.resize(n, vector<tint>());

    forn(i, m){
        tint a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bfs(0);

    if(parent[n-1] == -1){
        cout << "IMPOSSIBLE\n";
    }else{
        vector<tint> path;
        tint vertex = n-1;
        path.push_back(vertex);
        while(vertex != -1){
            vertex = parent[vertex];
            path.push_back(vertex);
        }

        cout << path.size()-1 << endl;
        for(tint i=path.size()-2; i>=0; i--){
            cout << path[i]+1 << " ";
        }cout << "\n";
    }


    return 0;
}