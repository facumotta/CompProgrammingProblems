#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    vector<int> ans;

    for(int i=0; i<t; i++){

        int n, k; cin >> n >> k;
        
        vector<int> test_case;

        vector<bool> obtained(n+1, false);

        int cant_k = 0;

        for(int j=0; j<n; j++){
            int a; cin >> a;
            test_case.push_back(a);
            obtained[a] = true;
            if(a == k) cant_k++;
        }   

        int changes = 0;
        for(int j=0; j<k; j++){
            if(!obtained[j]) changes++;
        }

        ans.push_back(max(changes, cant_k));
    }

    for(auto p: ans){
        cout << p << "\n";
    }


    return 0;
}