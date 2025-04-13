#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)


int main(){

    tint n, m, k; cin >> n >> m >> k;

    vector<tint> applicants;
    vector<tint> apartments;

    forn(i, 0, n){
        tint p; cin >> p;
        applicants.push_back(p);
    }

    forn(i, 0, m){
        tint p; cin >> p;
        apartments.push_back(p);
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    tint j=0;
    tint i=0;
    tint total = 0;
    
    while(i < applicants.size() && j < apartments.size()){
        if(abs(applicants[i] - apartments[j]) <= k){
            total++;
            i++;
            j++;
        }else{
            if(applicants[i] > apartments[j]){
                j++;
            }else{
                i++;
            }
        }

    }

    cout << total;

    return 0;
}

