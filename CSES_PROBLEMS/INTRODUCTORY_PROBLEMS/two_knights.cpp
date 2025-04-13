#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i++)
 

int main(){

    tint n;
    cin >> n;

    map<tint, tint> myDick = {{1,0}, {2,6}, {3,28}, {4,96}, {5,252}, {6,550}};
    forn(i, 1, n+1){
        if(i <= 6){
            cout << myDick[i] << "\n";
        }else{
            tint previo = myDick[i-1];
            tint sum1 = (i-1) * (i-1) * (2*i -1);
            tint attack1 = 4 + 6 + 2 *(i-5) * 4 + 6 + 4 + 2;
            tint sum2 = (2*i -1) * (2*i -2) / 2;
            tint attack2 = 2;
            tint total = previo + sum1 - attack1 + sum2 - attack2;
            myDick[i] = total;
            cout << total << "\n";
        }

    }


    return 0;
}

