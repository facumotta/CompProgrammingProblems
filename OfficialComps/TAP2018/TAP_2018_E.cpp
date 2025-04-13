#include <bits/stdc++.h>
 
using namespace std;
 
#define IZQ 0
#define DER 1
typedef long long tint;
vector<long double> probs_izq;
vector<long double> probs_der;
long double INF = 1e18;

vector<vector<vector<long double>>> matrixDP;
tint n;

long double dp_(tint i, tint j, tint pos){
    //cout << "i: " << i << " j: " << j << " pos: " << pos << endl;
    if(i == n && j == n){
        return 0;
    }else if(matrixDP[i][j][pos] != INF){
        return matrixDP[i][j][pos];
    }

    if(pos == IZQ){
        if(i+1 <= n){
            matrixDP[i+1][j][IZQ] = min(matrixDP[i+1][j][IZQ], dp_(i+1, j, IZQ) + probs_izq[n-1-i]);
            //cout << "i: " << i+1 << " j: " << j << " pos: " << pos << " value: " << matrixDP[i+1][j][IZQ] << endl;
        }
        if(j+1 <= n){
            matrixDP[i][j+1][DER] = min(matrixDP[i][j+1][DER], dp_(i, j+1, DER) + probs_der[j] * (j+i+1));
            //cout << "i: " << i << " j: " << j+1 << " pos: " << pos << " value: " << matrixDP[i][j+1][DER] << endl;   
        }
    }else{
        if(j+1 <= n){
            matrixDP[i][j+1][DER] = min(matrixDP[i][j+1][DER], dp_(i, j+1, DER) + probs_der[j]);
            //cout << "i: " << i << " j: " << j+1 << " pos: " << pos << " value: " << matrixDP[i][j+1][DER] << endl;   
        }
        if(i+1 <= n){
            matrixDP[i+1][j][IZQ] = min(matrixDP[i+1][j][IZQ], dp_(i+1, j, IZQ) + probs_izq[n-1-i] * (j+i+1)); 
            //cout << "i: " << i+1 << " j: " << j << " pos: " << pos << " value: " << matrixDP[i+1][j][IZQ] << endl;
        }
    }
    return INF;
}

/*
    (-2)---------(-1)--------0--------(1)--------(2)
            0           1         2         3
    min{
        f(i, j+1, der, dp(i, j+1, der)),
        f(i-1, j, izq, dp(i-1, j, izq))
    }
*/



int main(){
    cin >> n;
    long double sum1 = 0;
    long double sum2 = 0;
    for(tint i=0; i<n; i++){
        long double k;
        cin >> k;
        probs_izq.push_back(k);
    }
    for(tint i=0; i<n; i++){
        long double k;
        cin >> k;
        probs_der.push_back(k);
    }

    matrixDP.assign(n+2, vector<vector<long double>>(n+2, vector<long double>(2, INF)));
    long double a = dp_(0,0,DER);
    long double res = min(matrixDP[n][n][IZQ], matrixDP[n][n][DER]);
    cout << matrixDP[n][n][IZQ] << " " << matrixDP[n][n][DER] << endl;
    cout << fixed << setprecision(6) << res << "\n";
    return 0;
}