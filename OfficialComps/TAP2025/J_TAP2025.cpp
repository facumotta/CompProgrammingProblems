#include<bits/stdc++.h>
using namespace std;

typedef long long tint;

vector<vector<tint>> games;

map<tint, tint> dicc_1;
map<tint, tint> dicc_2;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tint T; cin >> T;
    games.resize(2*T);
    
    for(tint i=0; i<2*T; i++){
        tint K; cin >> K;

        for(tint j=0; j<K; j++){
            tint b; cin >> b;
            games[i].push_back(b);
            if(i<T){
                dicc_1[b]++;
            }else{
                dicc_2[b]++;
            }
        }
    }

    if((T>2) || (T == 1)){
        if(dicc_1 == dicc_2){
            cout << "S";
            return 0;
        }
        cout << "N";
        return 0;
    }else{
        
        if(dicc_1 != dicc_2){
            cout << "N";
            return 0;
        }

        tint a,b, min_ab;

        if((games[0].size()==0) || (games[1].size()==0)){
            if((games[0].size()==0) && (games[1].size()==0)){
                cout << "S";
                return 0;
            }else if(games[0].size()==0){
                min_ab = games[1][games[1].size()-1];
            }else{
                min_ab = games[0][games[0].size()-1];
            }

        }else{
            a = games[0][games[0].size()-1];
            b = games[1][games[1].size()-1];

            min_ab = min(a, b);
        }

 
        vector<tint> final_vector_1;
        vector<tint> final_vector_2;
        for(tint k = 0; k< games[0].size(); k++){
            if(games[0][k] != min_ab){
                final_vector_1.push_back(games[0][k]);
            }
        }   

        for(tint k = 0; k< games[2].size(); k++){
            
            if(games[2][k] != min_ab){
                final_vector_2.push_back(games[2][k]);
            }
        }

        if(final_vector_1 == final_vector_2){
            cout << "S";
            return 0;
        }else{

            // cout << "---------------\n";
            // cout << "Min_ab: " << min_ab << "\n";
            // for(auto v: final_vector_1){
            //     cout << v << " ";
            // }cout << "\n";
            // for(auto v: final_vector_2){
            //     cout << v << " ";
            // }cout << "\n";

            cout << "N";
            return 0;
        }


    }


    return 0;
}