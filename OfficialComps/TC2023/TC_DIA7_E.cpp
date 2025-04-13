#include <bits/stdc++.h>

using namespace std;

typedef long long tint;
#define forn(n) for(tint i = 0; i < n; i++)
#define forn_back(n) for(tint i = n-1; i >=0; i--)

signed main(){

    tint t;
    cin >> t;
    forn(t){
        tint n; cin >> n;        
        string s; cin >> s; 
        vector<pair<tint,tint>> cows;
        cows.assign(n, {0,0});

        tint left = 0;
        forn(n){
            if(s[i] == '.'){
                cows[i].first = left;
            }else{
                left++;
            }
        }
        
        tint right = 0;
        forn_back(n){
            if(s[i] == '.'){
                cows[i].second = right;
            }else{
                right++;
            }
        }

        tint res = 0;
        forn(n){
            if(s[i] == '.'){
                res += min(cows[i].first, cows[i].second);
            }
        }
        cout << res << "\n";
    }
}