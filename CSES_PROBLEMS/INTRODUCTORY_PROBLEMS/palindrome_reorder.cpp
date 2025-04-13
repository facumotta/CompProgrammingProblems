#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)

map<char, tint> myDicc;

int main(){

    string s;
    cin >> s;

    forn(i, 0, s.size()){
        myDicc[s[i]]++;
    }

    tint odd = 0;
    char odd_letter;

    for(auto l : myDicc){
        if(l.second %2 == 1){
            odd_letter = l.first;
            odd++;
        }
    }

    if(odd > 1){
        cout << "NO SOLUTION\n";
        return 0;
    }else{
        string palindrome;

        for(auto l : myDicc){
            if(l.first != odd_letter){
                forn(i, 0, l.second/2){
                    palindrome.push_back(l.first);
                }
            }
        }
        string rev = palindrome;
        reverse(rev.begin(), rev.end());

        forn(i, 0, myDicc[odd_letter]){
            palindrome.push_back(odd_letter);
        }
        

        cout << palindrome + rev;
    }

    return 0;
}

