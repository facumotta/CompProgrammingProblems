#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
tint INF = 1e18;
map<tint, tint> distintos;
 
int main(){
    tint n, m;
    cin >> n >> m;
 
    for(tint i=0; i<n; i++){
        tint k;
        cin >> k;
        distintos[k]++;
    }
    
    tint dist = distintos.size();

    if(dist == m){
        if(m==1){
            cout << 1 << "\n";
            return 0;
        }
        cout << 0 << "\n";
        return 0;
    }else if(dist == 1){
        cout << 1 << "\n";
        return 0;
    }else if(dist == 2){
        if(n==dist){
            cout << m-2 << "\n";
            return 0;
        }
        
        bool hay_numero_unico = false;
        for(auto num:distintos){
            if(num.second == 1){
                hay_numero_unico = true;
                break;
            }
        }
 
        if(hay_numero_unico){
            cout << m-1 << "\n";
            return 0;
        }else{
            cout << m << "\n";
            return 0;
        }
    }else{
        if(dist >= 3 && m>=5){
            cout << m << "\n";
            return 0;
        }else if(dist == 3 && n == 3){
            cout << 3 << "\n";
            return 0;
        }else{
            cout << 4 << "\n";
            return 0;
        }
    }
}