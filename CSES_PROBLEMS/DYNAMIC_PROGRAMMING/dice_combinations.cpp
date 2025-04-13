#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
 
using namespace std;
 
int n; 
vector<int> v(1000001,-1);
 
int solve(int n){
    if(v[n] != -1){
        return v[n];
    }else{
        int sum = 0;
        for(int i=1; i<=6; i++){
            if(n-i < 0){
                break;
            }else{
                sum += solve(n-i)%1000000007;
                sum = sum%1000000007;
            }
        }
        v[n] = sum%1000000007;
        return v[n]; 
    }
}
 
 
 
int main(){
    cin >> n;
    v[0] = 1;
    cout << solve(n);
    return 0;
}