#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)


int main(){

    string s;
    cin >> s;
    
    vector<string> permutations = {string(1, s[0])};

    forn(i, 1, s.size()){
        char adding = s[i];
        vector<string> temp_perm;
        
        for(auto p : permutations){
            forn(k, 0, p.size()+1){
                string new_permutation = p.substr(0, k) + adding + p.substr(k, p.size()-k);
                temp_perm.push_back(new_permutation);
            }
        }

        permutations = temp_perm;
    }

    set<string> set_ordenado(permutations.begin(), permutations.end());
    cout << set_ordenado.size() << "\n";
    for (auto val : set_ordenado) {
        cout << val << "\n";
    }

    return 0;
}

