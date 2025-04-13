#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)


int main(){

    vector<pair<tint, tint>> reserved;

    forn(i, 0, 8){
        string s; cin >> s;
        forn(j, 0, 8){
            if(s[j] == '*'){
                reserved.push_back({i, j});
            }
        }
    }


    vector<tint> distribution = {0,1,2,3,4,5,6,7};

    set<vector<tint>> valid_distributions;

    while(next_permutation(distribution.begin(), distribution.end())){
        set<tint> diag1;
        set<tint> diag2;
        forn(i, 0, distribution.size()){
            diag1.insert(i + distribution[i]);
            diag2.insert(distribution[i] - i);
        }

        if(diag1.size() == 8 && diag2.size() == 8){
            valid_distributions.insert(distribution);
        }

    }

    
    set<vector<tint>> final_distributions = valid_distributions;

    for(auto d: valid_distributions){
        for(auto p: reserved){
            if(d[p.first] == p.second){
                final_distributions.erase(d);
                break;
            }else continue;
        }
    }

    cout << final_distributions.size();

    return 0;
}

