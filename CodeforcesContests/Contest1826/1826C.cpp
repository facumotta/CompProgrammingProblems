#include <bits/stdc++.h>

using namespace std;

vector<int> divisores(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) {
                res.push_back(n / i);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    int t; cin >> t;

    for(int test=0; test<t; test++){
        int n, m;
        cin >> n >> m;

        if(n == 1){
            cout << "YES\n";
        }else if(n <= m){
            cout << "NO\n";
        }else{
            vector<int> div = divisores(n);
            int d;
            for(d=1; d<div.size(); d++){
                if(m >= div[d]){
                    cout << "NO\n";
                    break;
                }
            }
            if(d == div.size()){
                cout << "YES\n";
            }
        }
        
    }

}
