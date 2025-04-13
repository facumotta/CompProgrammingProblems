#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> grado;
int n,m,k;

set<int> no_visitados;
set<pair<int,int>> no_validos;



void dfs(int s,int e){
    //cout << "S " << s << " E " << e << endl;
    no_visitados.erase(s);
    auto it = no_visitados.begin();
    while(it != no_visitados.end()){
        int u = *it;
        if(no_validos.count({s,u}) == 0 && no_validos.count({u,s}) == 0){
            dfs(u,s);
        }
        it = no_visitados.upper_bound(*it);
    }
}




int main(){
    cin >> n >> m >> k;
    adj.resize(n+1);

    for(int i = 1; i <= n; i++) no_visitados.insert(i);
    for(int j = 0; j < m;j++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        no_validos.insert({a,b});
    }
    dfs(1,-1);
    
    if(!no_visitados.empty()){
        cout << "impossible";
        return 0;
    }
    int suma = 0;
    for(int i = 1; i <= n;i++){
        if(n - 1 - adj[i].size() == 0){
            cout << "impossible";
            return 0;
        }
        suma += (n - 1 - adj[i].size());
    }
    if(suma >= 2*(n-1) && k <= n - 1 - adj[1].size()){
        cout << "possible";
    }else{
        cout << "impossible";
    }

}