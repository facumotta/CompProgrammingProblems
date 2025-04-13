#include <bits/stdc++.h>
 
using namespace std;

typedef long long tint;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tint t;
    long double a, b, c;
    cin >> t;
    while(t>0){
        cin >> a >> b >> c;

        long double m = max(a,b);
        long double mmin = min(a,b);
        long double mitad = (m+mmin)/2; 

        long double res = (m-mitad)/c;

        if((tint) res == res) cout << (tint) res << "\n";
        else cout << (tint) (res +1) << "\n";
        t--;
    }

}

