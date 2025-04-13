#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i++)
 

int main(){

    tint n;
    cin >> n;

    vector<tint> sequence(n);
    forn(i, 0, n){
        tint k; cin >> k;
        sequence[i] = k;
    }   

    tint moves = 0;
    tint actual = sequence[0];

    forn(i, 1, n){
        if(sequence[i] < actual){
            moves += actual - sequence[i];
            sequence[i] = actual;
        }

        actual = sequence[i];
    }

    cout << moves;
    return 0;
}