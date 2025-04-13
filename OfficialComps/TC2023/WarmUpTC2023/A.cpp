#include <bits/stdc++.h>

using namespace std;


int main(){

    int a,b;

    vector<pair<int, int>> dots;
    
    for(int i=0; i<3; i++){
        cin >> a >> b;
        dots.push_back({a,b});
    }

    pair<int, int> punto1 = {dots[2].first + (dots[0].first - dots[1].first), dots[2].second + (dots[0].second - dots[1].second)};

    pair<int, int> punto2 = {dots[1].first + (dots[2].first - dots[0].first), dots[1].second + (dots[2].second - dots[0].second)};
    
    pair<int, int> punto3 = {dots[0].first + (dots[1].first - dots[2].first), dots[0].second + (dots[1].second - dots[2].second)}; 

    cout << 3 << endl;

    cout << punto1.first << " " << punto1.second << endl;
    cout << punto2.first << " " << punto2.second << endl;
    cout << punto3.first << " " << punto3.second << endl;    
}