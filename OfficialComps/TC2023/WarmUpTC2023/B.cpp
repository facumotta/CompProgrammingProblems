#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    set<string> names;
    for(int i=0; i<n; i++){
        string name;
        cin >> name;
        if(names.count(name)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        names.insert(name);
    }
}