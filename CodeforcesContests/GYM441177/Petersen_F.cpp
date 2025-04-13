#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> aristas;
vector<bool> visitado;

vector<int> componentes;
map<int, int> cont_vert_comp;

void dfs(int i, int num_comp){
    componentes[i] = num_comp;
    for(auto u : aristas[i]){
        if((componentes[u] == -1)){
            dfs(u, num_comp);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    aristas.resize(n);

    for(int i=0; i<m; i++){
        int t; cin >> t;
        int primero;
        if(t != 0) {cin >> primero;}
        for(int j=0; j<t-1; j++){
            int amigo; cin >> amigo;
            aristas[primero-1].push_back(amigo-1);
            aristas[amigo-1].push_back(primero-1);

        }
    }
    
    componentes.assign(n, -1);
    int numero_comp = 1;


    for(int i = 0; i < n; i++){
        if(componentes[i] == -1){
            dfs(i, numero_comp);
            numero_comp++;
        }
        cont_vert_comp[componentes[i]]++;
    }

    for(int i=0; i<n; i++){
        cout << cont_vert_comp[componentes[i]] << " ";
    }
}
    