#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)

pair<int, int> change_to_1_to_2(pair<int, int> p){
    pair<int, int> res = {0,0};

    if(p.first == 1) res.first = 1;
    if(p.second == 1) res.second = 1;
    
    if(p.first == 2) res.first = 3;
    if(p.first == 3) res.first = 2;

    if(p.second == 2) res.second = 3;
    if(p.second == 3) res.second = 2;

    return res;
}

pair<int, int> change_to_2_to_3(pair<int, int> p){
    pair<int, int> res = {0,0};

    if(p.first == 3) res.first = 3;
    if(p.second == 3) res.second = 3;
    
    if(p.first == 1) res.first = 2;
    if(p.first == 2) res.first = 1;

    if(p.second == 1) res.second = 2;
    if(p.second == 2) res.second = 1;

    return res;
}



int main(){

    int n;
    cin >> n;
    
    vector<pair<int, int>> solution_1_to_3 = {{1,3}};

    forn(k, 1, n){
        vector<pair<int, int>> new_solution;

        forn(i, 0, solution_1_to_3.size()){
            pair<int, int> step = solution_1_to_3[i];
            pair<int, int> new_step = change_to_1_to_2(step);
            new_solution.push_back(new_step);
        }
        new_solution.push_back({1,3});

        forn(i, 0, solution_1_to_3.size()){
            pair<int, int> step = solution_1_to_3[i];
            pair<int, int> new_step = change_to_2_to_3(step);
            new_solution.push_back(new_step);
        }

        solution_1_to_3 = new_solution;
    }


    cout << solution_1_to_3.size() << "\n";
    for(auto c: solution_1_to_3){
        cout << c.first << " " << c.second << "\n";
    }
    return 0;
}

