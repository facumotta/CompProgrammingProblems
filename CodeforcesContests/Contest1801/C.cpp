#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
 
using namespace std;


int main(){
    int c; cin >> c;
    for(int test = 0; test<c; test++){
        int n, m; cin >> n >> m;

        vector<vector<long long>> B(n, vector<long long>(m));
        long long p = (1LL << 62);
        long long k = 0;
        int itera = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i%2 == 0){
                    if(j%2 == 0){
                        B[i][j] = 2*j+k;
                    }else{
                        B[i][j] = 2*j-1+k;
                    }
                }else{
                    if(j%2 == 0){   
                        B[i][j] = 2*j+2+k;
                    }else{
                        B[i][j] = p+(2*j+1)+k;
                    }
                }
            }
            if(i%2 == 1){
                k = (itera) << 10;
                itera++;
            }
        }
        cout << n*m << "\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << B[i][j] << " ";
            }cout << "\n";
        }
    }

    return 0;
}