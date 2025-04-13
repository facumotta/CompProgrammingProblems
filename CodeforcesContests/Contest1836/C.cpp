#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int t; cin >> t;

    for(int test=0; test<t; test++){
        int a, b, c;long long k; cin >> a >> b >> c >> k;

        int A = pow(10, a)-1;
        int B = pow(10, b)-1;
        int C = pow(10, c-1);

       
        
        if(A+B < C){
            cout << -1 << endl;
        }else if((int)pow(10,a-1) + (int)pow(10,b-1) > (int)(pow(10,c)-1)){
            cout << -1 << endl;
        }else{
            
            A = (int)pow(10, a-1);
            int max_A = pow(10, a);
            int min_C = pow(10, c-1);
            int max_C = pow(10, c)-1;
            int max_B = min((int)pow(10, b)-1, max_C-A);
            int min_B = min_C - A;
            if(min_B <= 0) min_B = 1;
            
            while(k > 0 && A != max_A){

                int amount = max_B - min_B + 1;
                if((k - amount) > 0){
                    k -= amount;
                }else{
                    cout << A << " + " << min_B+(k-1) << " = " << A+min_B+(k-1) << endl;
                    break;
                }

                A++;
                min_B = min_C - A;
                if(min_B <= 0) min_B = 1;
            }

            if(k > 0 && A == max_A){
                cout << -1 << endl;
            }

        }

    }
}