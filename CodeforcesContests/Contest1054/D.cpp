#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){

    ll t; cin >> t;

    vector<ll> ans;

    for(ll l=0; l<t; l++){

        ll n; cin >> n;
        string s; cin >> s;

        vector<ll> idx_a;
        vector<ll> idx_b;

        ll sum_a = 0;
        ll sum_b = 0;

        for(ll i=0; i<n; i++){
            if(s[i] == 'a'){
                idx_a.push_back(i);
                sum_a += i;
            }else{
                idx_b.push_back(i);
                sum_b += i;
            }
        }

        if(idx_a.size() > 0 && idx_b.size() > 0){

            for(ll i=0; i<idx_a.size(); i++){
                idx_a[i] -= i;
            }

            for(ll i=0; i<idx_b.size(); i++){
                idx_b[i] -= i;
            }

            ll median_idx_a;
            ll median_idx_b;

            if(idx_a.size() % 2 == 1) median_idx_a = idx_a.size()/2;
            else median_idx_a = idx_a.size()/2 - 1;

            if(idx_b.size() % 2 == 1) median_idx_b = idx_b.size()/2;
            else median_idx_b = idx_b.size()/2 - 1;

            ll median_a = idx_a[median_idx_a];
            ll median_b = idx_b[median_idx_b];

            // cout << "medianas indices: ";
            // cout << median_a << " " << median_b << "\n";

            ll ans_a = 0;
            ll ans_b = 0;

            for(auto p: idx_a){
                ans_a += abs(p - median_a);
            }   

            for(auto p: idx_b){
                ans_b += abs(p - median_b);
            }

            // cout << "RES: " << min(ans_a, ans_b) << "\n";

            ans.push_back(min(ans_a, ans_b));
        }else{
            ans.push_back(0);
        }

    }

    for(auto p: ans){
        cout << p << "\n";
    }


    return 0;
}