#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long t; cin >> t;

    for(long long test=0; test<t; test++){
        long long n, k, g; cin >> n >> k >> g;
        
        long long coins = k*g;

        long long max_cpc;
        if(g%2 == 0){
            max_cpc = g/2 - 1;
        }else{
            max_cpc = g/2;
        }
        
        if((coins <= (n*max_cpc)) ){
            cout << coins << endl;
        }else{
            
            long long total = (n-1)*max_cpc;
            long long ultimo = coins - total;

            if(ultimo%g <= max_cpc){
                total += ultimo%g;
            }else{
                total -= g - (ultimo%g);
            }
            cout << total << endl;
            
        }
    }

    return 0;
}