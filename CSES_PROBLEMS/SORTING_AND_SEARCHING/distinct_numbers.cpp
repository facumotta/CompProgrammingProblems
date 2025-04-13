#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)
 
 
int main(){
 
    tint n; cin >> n;
 
    set<tint> nums;
    forn(i, 0, n){
        tint k; cin >> k;
        nums.insert(k);
    }
 
    cout << nums.size();
 
    return 0;
