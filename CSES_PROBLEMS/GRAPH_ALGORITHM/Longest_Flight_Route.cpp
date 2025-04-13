#include <bits/stdc++.h>
 
using namespace std;

#define forn(i, n) for(int i = 0; i < n; i++)

int n, m;
int INF = 1e9;
vector<vector<int>> adj;
vector<int> dist;
vector<int> parent;


void dfs(int s) {
    //indice, padre, visitados
    stack<pair<int, pair<int, int>>> q;
    q.push({s, {-1, 1}});
    
    while (!q.empty()) {
        auto u = q.top(); q.pop();
        for (auto v : adj[u.first]) {
            if(dist[v] < u.second.second){
                dist[v] = u.second.second;
                parent[v] = u.first;
                q.push({v, {u.first, u.second.second+1}});
            }
        }
    }
}




int main(){
    cin >> n >> m;
 
    adj.resize(n);
    dist.resize(n, -INF);
    parent.resize(n, -1); 

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        from--; to--;
        adj[from].push_back(to);
    }
    dist[0] = 1;

    dfs(0);

    if(dist[n-1] == -INF){
        cout << "IMPOSSIBLE";
    }else{
        cout << dist[n-1]+1 << endl;
        vector<int> viaje;
        int k = n-1;
        viaje.push_back(n);
        while(k != -1){
            viaje.push_back(parent[k]+1);
            k = parent[k];
        }

        for(int i=viaje.size()-2; i>=0; i--){
            cout << viaje[i] << " ";
        }


    }

}