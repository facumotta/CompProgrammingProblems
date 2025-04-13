#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)


int main(){

    tint n;
    cin >> n;

    vector<tint> nums;
    tint total = 0;
    forn(i, 0, n){
        tint k; cin >> k;
        nums.push_back(k);
        total += k;
    }

    vector<tint> sumas = {0};

    for(auto v:nums){
        vector<tint> temp_sum;
        for(auto s:sumas){
            temp_sum.push_back(s+v);
        }
        sumas.insert(sumas.end(), temp_sum.begin(), temp_sum.end());
    }

    tint minimo = 1e15;
    for(auto k:sumas){
        minimo = min(minimo, abs(total-2*k));
    }
    cout << minimo;

    return 0;
}

