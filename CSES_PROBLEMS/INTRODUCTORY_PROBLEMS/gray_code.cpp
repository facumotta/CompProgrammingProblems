#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)

int main(){

    tint n;
    cin >> n;
    
    vector<string> grayMap = {"0", "1"};

    forn(i, 1, n){
        vector<string> rev_grayMap = grayMap;
        reverse(rev_grayMap.begin(), rev_grayMap.end());

        forn(j, 0, grayMap.size()){
            grayMap[j] = "0" + grayMap[j];
        }

        forn(j, 0, rev_grayMap.size()){
            rev_grayMap[j] = "1" + rev_grayMap[j];
        }

        grayMap.insert(grayMap.end(), rev_grayMap.begin(), rev_grayMap.end());
    }

    for(auto s: grayMap){
        cout << s << "\n";
    }

    return 0;
}

