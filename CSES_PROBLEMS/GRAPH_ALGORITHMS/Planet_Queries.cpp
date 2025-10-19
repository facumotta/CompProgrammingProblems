#include <bits/stdc++.h>
 
using namespace std;
 
using ll = int;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll LOGN = log2(1e9)+1;


ll n, q;
vvll steps;
vll portals;

void precalculation(){

    for(ll i=0; i<n; i++){
        
        steps[i][0] = portals[i];
    }

    for(ll j=1; j<LOGN; j++){
        for(ll i=0; i<n; i++){
            steps[i][j] = steps[steps[i][j-1]][j-1];
        }
    }

    return;
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    cin >> n >> q;
    portals.resize(n);
    for(ll i=0; i<n; i++){ 
        cin >> portals[i];
        portals[i]--;
    }


    steps.resize(n, vll(LOGN));


    precalculation();

    // cout << "Hice precalculo\n"; 

    // for(auto p: steps){
    //     for(auto l :p){
    //         cout << l << " ";
    //     }cout << "\n";
    // }


    for(ll i=0; i<q; i++){
        ll x, k; cin >> x >> k;

        ll ans = x-1;

        for(ll p=0; p<LOGN; p++){
            if(k & (1 << p)){
                ans = steps[ans][p];
            }
        }

        cout << ans+1 << "\n";
    }


    return 0;
}