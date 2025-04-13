#include <bits/stdc++.h>

using namespace std;
//HAY QUE ARREGLARLO
using tint = long long;
#define forn(n) for(tint i = 0; i < n; i++)
#define forn_back(n) for(tint i = n-1; i >=0; i--)
tint n, k;
vector<vector<tint>> matrix_dp;
vector<tint> nums;

tint dp(tint cantnums, tint k, tint lnum){
    if(cantnums == 0 && k != -1){
        return 0;
    }else if(k == 0){
        //cout << "ultimo numero: " << nums[n-cantnums] << endl;
        return 1;
    }else if(cantnums < k){
        return 0;
    }/*else if(matrix_dp[cantnums][k] != -1){
        return matrix_dp[cantnums][k];
    }*/

    if(nums[cantnums] > lnum){
        tint res = dp(cantnums-1, k-1, nums[n-cantnums]) + dp(cantnums-1, k, lnum);
        matrix_dp[cantnums][k] = res;
        return res;
    }else{
        tint res = dp(cantnums-1, k, lnum);
        matrix_dp[cantnums][k] = res;
        return res;
    }
}


signed main(){
    cin >> n >> k;
    nums.resize(n);
    matrix_dp.resize(n+1, vector<tint>(k+2,-1));
    forn(n){
        cin >> nums[i];
    }

    cout << dp(5, k+1, -1);
}