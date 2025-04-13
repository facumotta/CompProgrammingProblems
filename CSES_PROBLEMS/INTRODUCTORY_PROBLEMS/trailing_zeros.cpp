#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)

int main(){

    tint n;
    cin >> n;

    tint res = 0;

    tint divisor = 5;
    while(true){
        if(n/divisor == 0){
            break;
        }else{
            res += n/divisor;
            divisor *= 5;
        }
    }

    cout << res;

    return 0;
}

