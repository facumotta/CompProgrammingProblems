#include <bits/stdc++.h>

using namespace std;


int main(){
    int t; cin >> t;

    for(int test=0; test<t; test++){
        int n; cin >> n;
        vector<int> nums(101,0);
        for(int i=0; i<n; i++){
            int k;
            cin >> k;
            nums[k]++;
        }
        int i;
        for(i=0; i<100; i++){
            if(nums[i] < nums[i+1]){
                cout << "NO" << endl;
                break;
            }
        }
        if(i == 100){
            cout << "YES" << endl;
        }


    }
    return 0;
}