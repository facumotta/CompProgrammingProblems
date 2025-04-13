#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tint t; cin >> t;

    for(tint j=0; j<t; j++){
        string s1, s2;
        cin >> s1 >> s2;
        tint i;
        for(i = 0; i<s1.size()-1; i++){
            char carac1= s1[i];
            char carac1_2= s1[i+1];
            
            char carac2= s2[i];
            char carac2_2= s2[i+1];
            
            if(carac1 == carac2 && carac1_2 == carac2_2 && carac1 == '0' && carac1_2 == '1'){
                cout << "YES\n";
                break;
            }
        }
        if(i == s1.size()-1){
            cout << "NO\n";
        }
    }

}
