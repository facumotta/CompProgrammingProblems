#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> res;
vector<bool> visited2;
vector<int> tin, low;
vector<int> art_points;
int timer;
set<pair<int, int>> cycle;

vector<bool> visitado;
vector<int> distancia;

bool bfs(int s) {
    visitado.assign(n, false);
    distancia.assign(n,0);
    visitado[s] = true;
    distancia[s] = 0;
    
    queue<int> q;
    q.push(s);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        for (auto v : adj[u]) {
            if (visitado[v]){
                res[u].push_back(v);
                res[v].push_back(u);
                return true;
            }
            res[u].push_back(v);
            res[v].push_back(u);
            visitado[v] = true;
            distancia[v] = distancia[u] + 1;
            q.push(v);
        }
    }

    return false;
}


void dfs2(int v, int p = -1) {
    visited2[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited2[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs2(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1){
                art_points.push_back(v);
            }
            ++children;
        }
    }
    if(p == -1 && children > 1){
        art_points.push_back(v);
    }
}

void find_cutpoints() {
    timer = 0;
    visited2.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited2[i]){
            dfs2(i);
        }
    }
}

vector<bool> visitado2;
bool dfs_basico(int v, int before) {
    visitado2[v] = true;
    for (int u : res[v]) {
        if (!visitado2[u]){
            if(dfs_basico(u, v)){
                cycle.insert({min(u,v), max(u,v)});
            }
        }else{
            if(u != before){
                cycle.insert({min(u,v), max(u,v)});
                return true;
            }

        }
        if(cycle.size()>0){
            cycle.insert({min(u,v), max(u,v)});
            break;
        }
    }
    return false;
}


int main(){

    int t; cin >> t;
    for(int test=0; test<t; test++){
        cin >> n >> m;
        adj.assign(n, vector<int>());
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        art_points.assign(0, 0);
        find_cutpoints();
        cycle.clear();
        for(auto v:art_points){
            if(adj[v].size() >= 4){
                res.assign(n, vector<int>());
                if(bfs(v)){
                    visitado2.assign(n, false);
                    dfs_basico(v, v);
                    int count = 0;
                    for(int i = 0; i<res[v].size(); i++){
                        if(cycle.count({min(v, res[v][i]), max(v, res[v][i])})){
                            continue;
                        }else{
                            cycle.insert({min(v, res[v][i]), max(v, res[v][i])});
                            count++;
                            if(count == 2) break;
                        }
                    }
                    break;
                }
            }
        }

        if(cycle.size() == 0){
            cout << "NO"<< endl;
        }else{
            cout << "YES" << endl;
            cout << cycle.size() << endl;
            for(auto e:cycle){
                cout << e.first+1 << " " << e.second+1 << endl;
            }
        }
    }

}
