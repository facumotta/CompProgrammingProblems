#include <bits/stdc++.h>

using namespace std;


int main(){

    int t; cin >> t;
    for(int test=0; test<t; test++){
        int n, k;
        cin >> n >> k;
        string opinion_primero;
        int res = n;
        for(int i=0; i< n; i++){

            string s; cin >> s;
            if(i==0){ 
                opinion_primero = s;
            }else{
                for(int j=0; j<k; j++){
                    if(opinion_primero[j] != s[j]){
                        res--;
                        break;
                    }
                }
            }
        }
        cout << res << endl;
    }
}