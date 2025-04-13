#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, n) for(tint i = 0; i < n; i++)
 

int main(){

    tint n;
    cin >> n;

    vector<tint> numbers(n);
    forn(i, n){
        numbers[i] = 1;
    }

    forn(i, n-1){
        tint k; cin >> k;
        k--;
        numbers[k] = 0;
    }

    forn(i, n){
        if(numbers[i] == 1){
            cout << i+1 << "\n";
            break;
        }else{
            continue;
        }
    }

    return 0;
}