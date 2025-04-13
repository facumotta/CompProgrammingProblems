#include <bits/stdc++.h>
 
using namespace std;

typedef long long tint;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    tint t; cin >> t;

    while(t>0){
        tint n, x, y;
        cin >> n >> x >> y;

        tint mult_lcm = n/(lcm(x,y));
        tint mult_x = n/x - mult_lcm;
        tint mult_y = n/y - mult_lcm;

        tint sumado = n*(n+1)/2 - ((n-mult_x)*(n-mult_x+1))/2;
        tint restado = (mult_y * (mult_y+1))/2;        

        cout << sumado - restado << "\n";

        t--;
    }

    return 0;
}