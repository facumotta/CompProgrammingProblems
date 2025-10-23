#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;

int main(){

    ll t; cin >> t;

    vll ans;

    while(t>0){
        ll n, k, l, r;

        cin >> n >> k >> l >> r;

        vll a;

        for(int i=0; i<n; i++){
            ll num; cin >> num;
            a.push_back(num);
        }

        map<ll, ll> freq_y;
        map<ll, ll> freq_x;


        ll x = 0;
        ll y = 0;
        ll sum = 0;

        for(int i = 0; i<n; i++){

            // cout << "i: " << i << "\n";
            // cout << "x: " << x << "\n";
            // cout << "y: " << y << "\n";

            while(y < n){
                if(freq_y.size() < k){
                    freq_y[a[y]]++;
                    y++;
                }else if(freq_y.size() == k){
                    if(freq_y.count(a[y]) == 1){
                        freq_y[a[y]]++;
                        y++;
                    }else{
                        break;
                    }
                }
            }

            if(x<i) x = i;

            while(x < y){
                if(freq_x.size() < k-1){
                    freq_x[a[x]]++;
                    x++;
                }else if(freq_x.size() == k-1){
                    if(freq_x.count(a[x]) == 1){
                        freq_x[a[x]]++;
                        x++;
                    }else{
                        break;
                    }
                }
            }



        

            if(y == n && freq_y.size() < k) continue;
            else {
                // if(y == n) y--;

                sum += max((ll) 0, min(y-1, i+r-1) - max(x, i+l-1) + 1);
            }

            // cout << "i: " << i << "\n";
            // cout << "x: " << x << "\n";
            // cout << "y: " << y << "\n";

            // cout << "dicc y resultante: \n";
            // for(auto p: freq_y){
            //     cout << p.first << " " << p.second << "\n";
            // }

            freq_x[a[i]]--;
            freq_y[a[i]]--;
            if(freq_x[a[i]] <= 0) freq_x.erase(a[i]);
            if(freq_y[a[i]] <= 0) freq_y.erase(a[i]);


            // cout << "SUMANDO: " << max((ll) 0, min(y-1, i+r-1) - max(x, i+l-1) + 1) << "\n";

            // cout << "-----------\n";
        }

        // cout << "RES: " << sum << "\n";
        ans.push_back(sum);


        t--;
    }

    for(auto p: ans){
        cout << p << "\n";
    }


    return 0;
}