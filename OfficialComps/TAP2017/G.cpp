#include <bits/stdc++.h>

using namespace std;

int n, m, p1, p2;
int modul = 1e9+7;

vector<vector<int>> matrix_dp_p1;
vector<vector<int>> matrix_dp_p2;

int dp_(vector<vector<int>>& matrix, int rondas_restantes, int p){
    cout << rondas_restantes << " " << p << endl;
    if(rondas_restantes == 0 && p == 0){
        return 1;
    }else if(rondas_restantes == 0){
        return 0;
    }else if(p < 0){
        return 0;
    }

    if(matrix[rondas_restantes][p] != -1){
        cout << "ENCONTRE "<< matrix[rondas_restantes][p] << endl;
        return matrix[rondas_restantes][p];
    }

    int sum = 0;
    for(int i=0; i<=m; i++){
        if(rondas_restantes > 0){
            sum += dp_(matrix, rondas_restantes-1, p-i);
        }
    }

    matrix[rondas_restantes][p] = sum;
    return matrix[rondas_restantes][p];
}


int main(){
    cin >> n >> m >> p1 >> p2;

    matrix_dp_p1.resize(101, vector<int>(1001, -1));
    matrix_dp_p2.resize(101, vector<int>(1001, -1));

    cout << dp_(matrix_dp_p1, n, p1) << endl;
    cout << "-------------"<< endl;
    cout << dp_(matrix_dp_p2, n, p2) << endl;

    cout << "aslfdsadf"<<endl;
    int sum = 0;
    for(int i=0; i<=n; i++){
        if(matrix_dp_p1[i][p1] == -1 || matrix_dp_p2[n-i][p2] == -1){
            continue;
        }else{
            cout << matrix_dp_p1[i][p1] << " " << matrix_dp_p2[n-i][p2] << endl; 
            sum += matrix_dp_p1[i][p1] * matrix_dp_p2[n-i][p2];
            sum = sum % modul;
        }
    }

    cout << sum;
    return 0;
}