#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, inicio, fin, salto) for(tint i = inicio; i < fin; i+= salto)
 

int main(){

    tint n;
    cin >> n;

    if(n<= 4){
        if(n == 1){
            cout << "1";
        }else if(n == 4){
            cout << "2 4 1 3";
        }else{
            cout << "NO SOLUTION";
        }
        return 0;
    }

    forn(i, 1, n+1, 2){
        cout << i << " ";
    }

    forn(i, 2, n+1, 2){
        cout << i << " ";
    }

    return 0;
}

