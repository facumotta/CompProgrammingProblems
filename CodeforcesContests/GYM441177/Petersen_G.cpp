#include <bits/stdc++.h>

using namespace std;


vector<pair<int,int>> cruces;
vector<vector<int>> aristas;
vector<bool> visitado;

vector<int> componentes;

void dfs(int i, int num_comp){
    componentes[i] = num_comp;
    for(auto u : aristas[i]){
        if((componentes[u] == -1)){
            dfs(u, num_comp);
        }
    }
}

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        cruces.push_back({a-1,b-1});
    }
    aristas.resize(cruces.size());
    for(int i=0; i<cruces.size();i++){
        for(int j=i+1; j<cruces.size();j++){
            if(cruces[i].first == cruces[j].first || cruces[i].second == cruces[j].second){
                aristas[i].push_back(j);
                aristas[j].push_back(i);
            }
        }   
    }

    
    componentes.assign(cruces.size(), -1);
    int numero_comp = 1;


    for(int i = 0; i < n; i++){
        if(componentes[i] == -1){
            dfs(i, numero_comp);
            numero_comp++;
        }
    }

    cout << numero_comp-2;
}