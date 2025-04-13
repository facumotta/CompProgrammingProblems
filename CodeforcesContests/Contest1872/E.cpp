#include <bits/stdc++.h>
 
using namespace std;

typedef long long tint;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    tint t; cin >> t;
    
    while(t>0){
        tint a, b;
        cin >> a >> b;
        tint c = a ^ b ^ 7;
        cout << bitset<18>(c).to_string();        
        t--;
    }
}