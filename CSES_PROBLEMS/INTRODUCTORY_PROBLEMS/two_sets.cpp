#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)
 

void printeando_vector( vector<tint> &v){
    for(auto i :v){
        cout << i << " ";
    }cout << "\n";
    return;
}

int main(){

    tint n;
    cin >> n;

    if((n*(n+1)/2) % 2 == 1){
        cout << "NO\n";
        return 0;
    }

    vector<tint> set1;
    vector<tint> set2;
    if(n%2 == 0){
        tint sum = (n*(n+1)/2);
        tint parejas = sum/(2*n);
        forn(i, 1, parejas + 1){
            set1.push_back(i);
            set1.push_back(n+1-i);
        }
        forn(i, parejas + 1, n/2 + 1){
            set2.push_back(i);
            set2.push_back(n+1-i);
        }
    }else{
        tint sum = (n*(n+1)/2);
        tint parejas = sum/(2*n);

        forn(i, 1, parejas + 1){
            set1.push_back(i);
            set1.push_back(n-i);
        }

        forn(i, parejas + 1, (n-1)/2 + 1){
            set2.push_back(i);
            set2.push_back(n-i);
        }
        set2.push_back(n);
    }


    cout << "YES\n";
    cout << set1.size() << "\n";
    printeando_vector(set1);
    cout << set2.size() << "\n";
    printeando_vector(set2);

    return 0;
}

