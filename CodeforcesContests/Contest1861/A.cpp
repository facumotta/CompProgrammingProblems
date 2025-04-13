#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tint t; cin >> t;

    for(tint  i=0; i<t; i++){
        string k;
        cin >>  k;
        bool aparecio_1 = false;
        bool aparecio_3 = false;
        for(auto c:k){
            if(c == '3'){
                if(aparecio_1){
                    cout << "13\n";
                    break;
                }else{
                    cout << "31\n";
                    break;
                }
            }else if(c == '1'){
                aparecio_1 = true;
            }
        }
    }

    return 0;
}