#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)

tint MOD = 1e9 + 7; 


int main(){

    tint n;
    cin >> n;

    tint res = 1;
    forn(i, 1, n+1){
        res *= 2;
        res %= MOD;
    }

    cout << res;

    return 0;
}

