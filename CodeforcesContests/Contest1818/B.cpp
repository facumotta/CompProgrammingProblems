#include <bits/stdc++.h>

using namespace std;


int main(){

    int t; cin >> t;
    for(int test=0; test<t; test++){
        int n; cin >> n;
        if(n == 1 || n == 2){
            for(int i= 1; i<= n; i++){
                cout << i << " ";
            }cout << endl;
        }else if(n%2 == 1){
            cout << -1 << endl;
        }else{
            for(int i = n; i>=1; i--){
                if(i%2 == 0){
                    cout << i-1 << " ";
                }else{
                    cout << i+1 << " ";
                }
            }cout << endl;
        }      
        
    }

}