#include <bits/stdc++.h>

using namespace std;

int t, n;

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

bool es_palindromo(vector<int> num){
    for(int i=0; i<n; i++){
        if(num[i] != num[n-i-1]){
            return false;
        }
    }
    return true;
}




int main(){

    cin >> t;
    for(int test=0; test<t; test++){
        cin >> n;
        vector<int> numeros(n);
        for(int i=0; i<n; i++){
            cin >> numeros[i];
        }

        if(es_palindromo(numeros)){
            cout << 0 << "\n";
        }else{
            int it = 0;
            while(abs(numeros[n-it-1] - numeros[it]) == 0){
                it++;
            }

            vector<int> divi = divisores(abs(numeros[n-it-1] - numeros[it]));

            for(int d=divi.size()-1; d >= 0; d--){
                vector<int> temp_array(n);
                for(int j=0; j<n; j++){
                    temp_array[j] = numeros[j] % divi[d];
                }

                if(es_palindromo(temp_array)){
                    cout << divi[d] << "\n";
                    break;
                }   
            }
        }

    }

}