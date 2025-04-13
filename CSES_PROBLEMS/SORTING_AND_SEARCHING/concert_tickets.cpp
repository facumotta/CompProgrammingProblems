#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long tint;
 
#define forn(i, inicio, fin) for(tint i = inicio; i < fin; i ++)

tint n, m;
vector<pair<tint, bool>> tickets;

tint search_valid_ticket(tint k){
    while(k >=0){
        if(tickets[k].second){
            return k;
        }
        k--;
    }   
    
    return -1;
}

void binary_search(tint x){

    int a = 0, b = n-1;
    while (a <= b) {
        int k = (a+b)/2;
        if ((k==n-1) || (tickets[k].first <= x && tickets[k+1].first > x)) {
            tint tick_pos = search_valid_ticket(k);

            if(tick_pos == -1) cout << -1 << "\n";
            else{
                tickets[tick_pos].second = false;
                cout << tickets[tick_pos].first << "\n";
            }
            return ;
        }
        if (tickets[k].first > x) b = k-1;
        else a = k+1;
    }
    return;
}

void print(){
    forn(i, 0, tickets.size()){
        cout << "{" << tickets[i].first << "," << tickets[i].second << "} ; ";
    }cout << "\n";
}


int main(){

    cin >> n >> m;

    vector<tint> customers;

    forn(i, 0, n){
        tint p; cin >> p;
        tickets.push_back({p, true});
    }

    forn(i, 0, m){
        tint p; cin >> p;
        customers.push_back(p);
    }

    sort(tickets.begin(), tickets.end());

    //print();

    forn(i, 0, customers.size()){
        binary_search(customers[i]);
        //print();
    }


    return 0;
}

