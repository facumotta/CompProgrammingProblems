#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i++)
 

int main(){

    string k;
    cin >> k;

    tint maxSub = 1;
    tint seqActual = 1;
    char letraActual = k[0];

    forn(i, 1, k.size()){
        if(k[i] == letraActual) seqActual +=1;
        else{
            if(seqActual > maxSub){
                maxSub = seqActual;
            }
            letraActual = k[i];
            seqActual = 1;
        }
    }

    maxSub = max(maxSub, seqActual);
    cout << maxSub;
    return 0;
}