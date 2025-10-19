#include <bits/stdc++.h>

using namespace std;

// Cualquiera menor a 1048576 = 2e20
int nro_random = 182551;
int valor;

int buscar_n(){

    int valor_0 = -1;
    for(int i=3; i<21; i++){

        for(int j=1; j <= (2*i+1); j++){
            
            cin >> valor;

            // cout << "i: " << i << "| j: " << j << "";

            if(j == 1){
                if((valor != valor_0) && (i>3)) return i-1;
                else valor_0 = valor;
            }
            
            if(j <= i){
                cout << "? right" << endl;
            }else if(j == i+1){
                cout << "? flip" << endl;
            }else{
                cout << "? left" << endl;
            }
        }
    }

    // Continua simulacion
    queue<int> og;
    queue<int> last_20;
    for(int i=0; i<21; i++){

        cin >> valor;
        int bit_nro;
        if((nro_random & (1<<i)) != 0) bit_nro = 1;
        else bit_nro = 0;

        if(valor != bit_nro){ 
            
            cout << "? flip" << endl;
            cin >> valor;
            cout << "? right" << endl;

        }else cout << "? right" << endl;

        og.push(bit_nro);
        last_20.push(bit_nro);
    }


    
    cin >> valor;
    last_20.pop(); last_20.push(valor);
    cout << "? right" << endl;
    
    int steps = 0;
    while((og != last_20)){
        cin >> valor;
        last_20.pop(); last_20.push(valor);
    
        steps++;
        cout << "? right" << endl;
    }

    return steps+1;
}




int main(){


    // for(int i=0; i<17; i++){
    //     if((nro_random & (1<<i)) != 0) cout << 1;
    //     else cout << 0;
    // }cout << "";

    int ans = buscar_n();

    cout << "! " << ans << endl;
    
    return 0;
}