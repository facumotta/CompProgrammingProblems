#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int n,k,d;

vector<vector<pair<int,int>>> aristas;
vector<bool> visitado;
vector<int> distancia;
map<pair<int,int>,int> indice;
vector<int> descartadas;


void bfs(int s) {
    visitado[s] = true;
    distancia[s] = 0;
    
    queue<pair<int,int>> q;
    q.push({s,-1});
    
    while (!q.empty()) {

        
        int u = q.front().first;
        int ant = q.front().second;
        q.pop();
        
        for (auto p : aristas[u]) {
            auto v = p.first;
            if (visitado[v]){
                if(u < v && v != ant){
                    descartadas.push_back(p.second);
                }
                continue;
            }
            visitado[v] = true;
            distancia[v] = distancia[u] + 1;
            q.push({v,u});
        }
    }
}

int main(){
    cin >> n >> k >> d;

    aristas.resize(n+1);
    distancia.resize(n+1);
    visitado.resize(n+1);
    for(int i = 0; i < k;i++){
        int t; cin >> t;
        aristas[0].push_back({t,-1});
    }
    for(int i = 0; i < n-1;i++){
        int u,v; cin >> u >> v;
        aristas[u].push_back({v,i});
        aristas[v].push_back({u,i});
    }
    bfs(0);
    cout << descartadas.size() << "\n";
    for(auto x:descartadas) cout << x+1 << " ";

}