#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i++)
 

int main(){

    tint t;
    cin >> t;

    forn(i, 0, t){
        tint fila, columna;
        cin >> fila >> columna;

        tint maxim = max(fila, columna);
        tint value = maxim*maxim;

        pair<tint, tint> pos;
        if(maxim %2 == 1){
            pos = {1, maxim};
        }else{
            pos = {maxim, 1};
        }

        value -= abs(pos.first - fila);
        value -= abs(pos.second - columna);

        cout << value << "\n";
    }


    return 0;
}

