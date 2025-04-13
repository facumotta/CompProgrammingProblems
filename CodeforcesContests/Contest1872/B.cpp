#include <bits/stdc++.h>
 
using namespace std;

typedef long long tint;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tint t;
    cin >> t;
    while(t>0){
        tint n;
        cin >> n;
        tint a, b;
        set<pair<tint, tint>> traps;
        for(tint i=0; i<n; i++){
            cin >> a >> b;
            traps.insert({a,b});
        }
        tint res = 1e18;
        for(auto p:traps){
            tint add = (p.second-1)/2;
            res = min(res, p.first + add);
        }
        cout << res << "\n";
        t--;
    }

}