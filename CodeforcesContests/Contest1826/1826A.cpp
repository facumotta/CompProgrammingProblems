#include <bits/stdc++.h>

using namespace std;


int main(){

    int t, n;
    cin >> t;
    vector<int> p;
    for(int test = 0; test < t; test++){
            cin >> n;
            p.assign(n, 0);
            for(int i=0; i<n; i++){
                cin >> p[i];
            }
        
        int x;
        for(x = n; x > -1; x--){
            int liars = 0;
            for(int i=0;i < n; i++){
                if(p[i] > x){
                    liars++;
                }
            }
            if(liars == x){
                cout << liars << "\n";
                break;
            }
        }
        if(x == -1){
            cout << -1 << "\n";
        }
        
    }
}