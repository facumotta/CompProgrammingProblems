#include <bits/stdc++.h>

using namespace std;

int main(){

    int t; cin >> t;

    vector<int> ans;

    for(int i=0; i<t; i++){

        int k; cin >> k;
        
        int cant_menos = 0;
        int cant_zeros = 0;

        for(int j=0; j<k; j++){
            int a; cin >> a;

            if(a == 0){
                cant_zeros++;
            }else if(a == -1){
                cant_menos++;
            }
        }   

        if(cant_menos % 2 == 0){
            ans.push_back(cant_zeros);
        }else{
            ans.push_back(cant_zeros + 2);
        }

    }

    for(auto p: ans){
        cout << p << "\n";
    }


    return 0;
}