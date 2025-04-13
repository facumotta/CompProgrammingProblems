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
int MOD = 1e9+7;
 
int get_posibilities(int k){
    
    if(v[k] != -1){
        return v[k];
    }else{
        long long sum = 0;
        for(int i=0; i<n; i++){
            if((k-coins[i]) < 0){
                continue;
            }else{  
                sum += get_posibilities(k-coins[i])%MOD;
            }
        }
        v[k] = sum % MOD;
        return v[k];
    }
}
 
 
int main(){
    cin >> n;
    cin >> x;
    for(int i=0; i<n; i++){int k; cin >> k; coins.push_back(k);}
    v[0] = 1;
    cout << get_posibilities(x);
    return 0;
}
 
