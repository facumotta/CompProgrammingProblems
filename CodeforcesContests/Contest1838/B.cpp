#include <bits/stdc++.h>

using namespace std;


int main(){

    int t; cin >> t;

    for(int test=0; test<t; test++){
        int n; cin >> n;
        vector<int> nums;
        nums.assign(n,0);
        int index1, index2, indexN;
        for(int i=0; i<n; i++){
            cin >> nums[i];
            if(nums[i] == 1){
                index1 = i+1;
            }else if(nums[i] == 2){
                index2 = i+1;
            }else if(nums[i] == n){
                indexN = i+1;
            }
        }

        if((index1 < indexN && indexN < index2) || (index2 < indexN && indexN < index1)){
            cout << indexN << " " << indexN << "\n";
        }else{
            if(index1 < indexN && index2 < indexN){
                cout << indexN << " " << max(index1, index2) << "\n";
            }else if(index1 > indexN && index2 > indexN){
                cout << indexN << " " << min(index1, index2) << "\n";
            }
        }
    }

    return 0;
}