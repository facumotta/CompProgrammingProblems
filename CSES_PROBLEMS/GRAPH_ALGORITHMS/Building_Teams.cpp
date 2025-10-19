#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;

#define forn(i, n) for(tint i = 0; i < n; i++)

vector<vector<tint>> adj;
vector<bool> visited;
vector<tint> team;
tint n, m;
bool posible = true;

void bfs(int s) {
    visited[s] = true;
    team[s] = 1;
    
    queue<int> q;
    q.push(s);
    
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        tint color = team[u];

        for (auto v : adj[u]) {
            if (visited[v]){
                if(team[v] == team[u]){
                    posible = false;
                    return;
                }
            }else{ 
                if(color == 1){
                    visited[v] = true;
                    team[v] = 2;
                    q.push(v);
                }else{
                    visited[v] = true;
                    team[v] = 1;
                    q.push(v);
                }
            }

        }
    }
}


int main(){
    cin >> n >> m;

    visited.resize(n, false);
    team.resize(n, -1);
    adj.resize(n, vector<tint>());

    forn(i, m){
        tint a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    forn(i, n){
        if(!visited[i]){
            bfs(i);
        }
    }

    if(!posible){
        cout << "IMPOSSIBLE\n";
    }else{
        forn(i, n) cout << team[i] << " ";
    }cout << "\n";

    return 0;
}