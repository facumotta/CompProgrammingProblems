#include <bits/stdc++.h>
 
using namespace std;

typedef long long tint;

tint is_prime(tint n){
    for(tint i=2; i< (tint) sqrt(n)+1; i++){
        if(n%i == 0){
            return i;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    tint t; cin >> t;

    while(t>0){
        tint a, b;
        cin >> a >> b;
        if(a<b){
            if(a>2){
                if(a%2 == 0){
                    cout << 2 << " " << a-2 << "\n";
                }else{
                    cout << 2 << " " <<a-1 << "\n";
                }
            }else{
                if(b>3){
                    cout << 2 << " " << 2 << "\n"; 
                }else{
                    cout << -1 << "\n";
                }
            }

        }else{
            tint k = is_prime(a);
            if(k == -1){
                cout << -1 << "\n";
            }else{
                cout << k << " " << a-k << "\n";
            }
        }

        t--;
    }

    return 0;
}

