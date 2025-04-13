#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, n) for(tint i = 0; i < n; i++)
 

int main(){

    tint n;
    cin >> n;

    vector<tint> sequence;
    sequence.push_back(n);

    while(n!= 1){
        if(n%2 == 0) n = n/2;
        else n = 3*n + 1;
    
        sequence.push_back(n);
    }

    forn(i, sequence.size()){
        cout << sequence[i] << " ";
    }cout << "\n";

    return 0;
}