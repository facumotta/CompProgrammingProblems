#include <bits/stdc++.h>

using namespace std;

int main(){

    int t; cin >> t;

    vector<int> ans;

    for(int i=0; i<t; i++){

        int k; cin >> k;
        
        vector<int> test_case;

        for(int j=0; j<k; j++){
            int a; cin >> a;
            test_case.push_back(a);
        }   

        sort(test_case.begin(), test_case.end());


        int max_diff = -1;
        for(int j=0; j<k-1; j += 2){
            max_diff = max(max_diff, abs(test_case[j] - test_case[j+1]));
        }

        ans.push_back(max_diff);
    }

    for(auto p: ans){
        cout << p << "\n";
    }


    return 0;
}