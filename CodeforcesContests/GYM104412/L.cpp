#include <bits/stdc++.h>

using namespace std;

typedef long long tint;

tint N,A,B,C;
vector<tint> problems;
tint sum_tot;

tint capA, capB, capC;
tint tempA, tempB;

bool posible(int s){

    if(s == N){
        return true;
    }
    bool flag = false;

    if(capA - problems[s] >=0){
        capA -= problems[s];
        flag = posible(s+1);
        capA += problems[s];

        if(flag)
            return true;

        if(capB - problems[s] >= 0){
            capB -= problems[s];
            flag = posible(s+1);
            capB += problems[s];
            
            if(flag)
                return true;
        }else{
            if((capC-problems[s])>=0){
                capC -= problems[s];
                flag = posible(s+1);
                capC += problems[s];
            
                if(flag)
                    return true;
            }
        }
    }else{
        if(capB - problems[s] >= 0){
            capB -= problems[s];
            flag = posible(s+1);
            capB += problems[s];
            
            if(flag)
                return true;
        }else{
            if((capC-problems[s])>=0){
                capC -= problems[s];
                flag = posible(s+1);
                capC += problems[s];
            
                if(flag)
                    return true;
            }
        }
    }
    return flag;
}



void solve(){
    


    for(int t=1; t<505; t++){

        capA = t*A;
        capB = t*B;
        capC = t*C;

        if(capA+capB+capC < sum_tot)
            continue;
        
        if((capA >= sum_tot) || (capB >= sum_tot) || (capC >= sum_tot)){
            cout << t;
            return;
        }


        tempA = 0;
        tempB = 0;

        if(posible(0)){
            cout << t;
            return;
        }


    }


    return;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> A >> B >> C;

    problems.resize(N);


    sum_tot = 0;
    for(int i=0; i<N; i++){
        cin >> problems[i];
        sum_tot += problems[i];
    }


    solve();


    return 0;
}