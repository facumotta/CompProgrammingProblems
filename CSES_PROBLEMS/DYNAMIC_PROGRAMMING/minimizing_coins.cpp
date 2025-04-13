#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
 
using namespace std;
 
int n;
int x;
vector<int> coins;
vector<int> v(1e6+1, -1);
int max_int = 2147483647;
 
 
int minimize_coins(int x){
    if(v[x] != -1){
        return v[x];
    }else{
        int min_coins = max_int;
        for(int i=0; i<n; i++){
            if((x-coins[i]) < 0){
                continue; 
            }else{
                min_coins = min(min_coins, minimize_coins(x-coins[i]));
            }
        }
        if(min_coins != max_int)v[x] = 1 + min_coins; else v[x] = min_coins;
        return v[x];
    }
}
 
 
 
int main(){
    cin >> n;
    cin >> x;
    for(int i=0; i<n; i++){int k; cin >> k; coins.push_back(k);}
    v[0] = 0;
    int count_coins = minimize_coins(x);
    if(count_coins != max_int) cout << count_coins; else cout << -1;
    return 0;
}