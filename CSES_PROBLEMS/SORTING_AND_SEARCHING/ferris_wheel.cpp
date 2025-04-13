#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)


int main(){

    tint n, x; cin >> n >> x;

    vector<tint> children;
    forn(i, 0, n){
        tint p; cin >> p;
        children.push_back(p);
    }

    sort(children.begin(), children.end());

    tint i = 0;
    tint j = children.size()-1;
    
    tint total = 0;
    while(i<=j){
        if(i == j){
            total++;
            break;
        }else{
            if(children[i]+children[j] <= x){
                i++;
                j--;
                total++;
            }else{
                j--;
                total++;
            }
        }
    }

    cout << total;

    return 0;
}

