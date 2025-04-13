#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
using tint = long long;
 
struct nodo{
    tint tag;
    tint padre;
    bool alive;
    vector<tint> hijos = {};
};
 
vector<nodo> reino;
//map<pair<tint, tint>, tint> visited;
vector<vector<pair<tint, tint>>> adj; 
tint find_new_mon(nodo &persona, tint iter){
    vector<tint>& hjs = persona.hijos;
    /*
    cout << "la persona " << persona.tag << " tiene como hijos: " << endl;
    for(auto h: hjs){
        if(reino[h].alive){
            cout << h << " ";
        }
    }cout << endl;
    */
    if(hjs.size() != 0){
        for(tint i=0; i<hjs.size(); i++){
            //pair<tint, tint> edge = {persona.tag , reino[h].tag};
            //visited[edge]++;
            adj[persona.tag][i].second++;
            if(reino[hjs[i]].alive == false && adj[persona.tag][i].second < 2){
                tint new_mon = find_new_mon(reino[hjs[i]], iter + 1);
                if(new_mon == -1) continue;
                else return new_mon;
            }else if(reino[hjs[i]].alive == true){
                return reino[hjs[i]].tag;
            }
        }


        auto it = std::lower_bound(reino[persona.padre].hijos.begin(), reino[persona.padre].hijos.end(), persona.tag);

        adj[reino[persona.padre].tag][(it - reino[persona.padre].hijos.begin())].second++;
        return find_new_mon(reino[persona.padre], iter+1);
    }else{

        auto it = std::lower_bound(reino[persona.padre].hijos.begin(), reino[persona.padre].hijos.end(), persona.tag);

        adj[reino[persona.padre].tag][(it - reino[persona.padre].hijos.begin())].second++;
        if(iter == 0){
            return find_new_mon(reino[persona.padre], iter+1);
        }else{
            return -1;
        }
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tint n; scanf("%lld", &n);
    reino.resize(n+1);
    adj.resize(n+1);
 
    tint monarca = 1; 
 
    reino[monarca] = {1,-1,true,{}};
    tint p_num = 1;
    for(tint i=1; i<=n; i++){
        tint a, b;
        scanf("%lld", &a);
        scanf("%lld", &b);
        if(a == 1){
            p_num++;
            nodo new_persona = {p_num,b,true,{}};
 
            reino[new_persona.tag] = new_persona;
            reino[new_persona.padre].hijos.push_back(new_persona.tag);

            adj[new_persona.padre].push_back({new_persona.tag, 0});
        }else{
            if(monarca == b){
 
                reino[b].alive = false;
            
                monarca = find_new_mon(reino[monarca], 0);
                printf("%lld\n", monarca);
            }else{
                reino[b].alive = false;
                printf("%lld\n", monarca);
            }
 
        }
    }
 
    return 0;
}
