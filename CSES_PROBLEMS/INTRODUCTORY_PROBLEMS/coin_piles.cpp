#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)

bool valid_Setup(tint x, tint y){
    tint a = (2*x-y)/3;
    tint b = x - 2*a;

    if(a>=0 && b>=0){
        return true;
    }else{
        return false;
    }
}

int main(){

    tint t;
    cin >> t;

    tint a, b;
    forn(i, 0, t){
        cin >> a >> b;
        if((a+b)%3 == 0){
            if(valid_Setup(a,b)){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}

