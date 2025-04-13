#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> incompatibilidad;
vector<pair<int, int>> remeras;


int main(){
    
    int n; cin >> n;
    
    incompatibilidad.resize(n, vector<int>(n));
    remeras.resize(n, {-1,-1});

    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        for (int j = 0; j < n; j++) {
            incompatibilidad[i][j] = line[j] - '0'; 
        }
    }
    
    remeras[0] = {0,0};
    int max_col_letra = 0;
    int max_col_fondo = 0;

    for(int i=1; i<n; i++){
        vector<int> rem_incomp;
        for(int j=0; j<i; j++){
            if(incompatibilidad[i][j] == 1){
                rem_incomp.push_back(j);
            }
            if(rem_incomp.size() >= 2){
                break;
            }
        }

        if(rem_incomp.size() >= 2){
            pair<int, int> remera1 = remeras[rem_incomp[0]];
            pair<int, int> remera2 = remeras[rem_incomp[1]];
        
            if(remera1.first == remera2.first){
                remeras[i] = {remera1.first, max_col_fondo + 1};
            }else{
                remeras[i] = {max_col_letra + 1, remera1.second};
            }
        }else if(rem_incomp.size() == 1){
            remeras[i] = {remeras[rem_incomp[0]].first, max_col_fondo + 1};
        }else{
            remeras[i] = {max_col_letra + 1, max_col_fondo + 1};
        }

        max_col_letra = remeras[i].first;
        max_col_fondo = remeras[i].second;
    }

    for(int i=0; i<n; i++){
        cout << remeras[i].first << " " << remeras[i].second << "\n";
    }


    return 0;
}