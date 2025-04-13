#include <bits/stdc++.h>

using namespace std;
int INF = 1e9;
vector<int> nums;
vector<vector<int>> matrix;

int dp_f(int l, int r, int i, int j){
    
    if(matrix[l][r] != 0){
        return matrix[l][r];
    }else if(l == r){
        if(!(i >= j && j >= nums[l])){
            matrix[l][r] = 1;
            return matrix[l][r];
        }
    }else{
        int posible_max = 0;
        if(!(i >= j && j >= nums[l])){
            posible_max = dp_f(l+1, r, j, nums[l]) + 1;
        }
        matrix[l][r] = max(posible_max, dp_f(l+1, r, i, j));
        return matrix[l][r];
    }
    return 0;
}


int main(){
    int n, q;
    cin >> n >> q;

    nums.assign(n,0);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    matrix.assign(n, vector<int>(n,0));

    for(int i=0; i<q; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << dp_f(l, r, -INF, -INF) << endl;
    }

}