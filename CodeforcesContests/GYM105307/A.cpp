#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
    
typedef long long tint; 
    
tint p = 1e9+7;
    
    
tint modInverse(tint a, tint p) {
    tint result = 1;
    tint power = p - 2; // Para inverso modular, usar a^(p-2) % p cuando p es primo
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * a) % p;
        }
        a = (a * a) % p;
        power /= 2;
    }
    return result;
}
 
// Función principal para calcular a
tint findA(tint x, tint y) {
    tint y_inv = modInverse(y, p); // Encuentra el inverso modular de y
    tint a = (x * y_inv) % p;     // Calcula a tal que a * y ≡ x (mod MOD)
    return a;
}
    
int main() {
    
    tint t;
    cin >> t;
    
    tint ganar_n = 1;
    tint perder_n = 0;
    tint denom = 1;

    while(t!=0){
        t--;
        tint r, a;
        cin >> r >> a;

        tint t = r+a;

        tint next_ganar = ganar_n * r + perder_n * a;
        tint next_perder = perder_n * r + ganar_n * a;

        ganar_n = next_ganar;
        perder_n = next_perder;

        denom *= t;

        tint k1 = __gcd(ganar_n, denom);
        tint k2 = __gcd(perder_n, denom);

        tint k3 = __gcd(k1,k2);

        ganar_n /= k3;
        perder_n /= k3;
        denom /= k3;

        cout << "Proba ganar: " << ganar_n << " / " << denom << endl;
        cout << "Proba perder: " << perder_n << " / " << denom << endl;
    }
 
    cout << ganar_n << " / " << denom <<  " mod(" << p << ")" << endl; 
    
    tint res = findA(ganar_n, denom);
    cout << res%p << endl;
    
    cout << (denom * res) % p << endl;
}