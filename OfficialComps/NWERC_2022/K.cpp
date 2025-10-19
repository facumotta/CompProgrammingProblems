
#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> adj;
set<pair<int, int>> edges;
vector<int> cc;
vector<bool> visited;
set<int> cc_cycles;

bool chequear_vecinos(int s){

    int nodos_no_leaf = 0;

    for(auto v: adj[s]){
        if(v != s){
            for(auto vi:adj[v]){
                if(vi != s){
                    nodos_no_leaf++;
                    break;
                }
            }
        }
    }

    // cout << "nodo i: " << s+1 << " tiene no_leaf: " << nodos_no_leaf << "\n";

    if(nodos_no_leaf >= 3) return true;
    else return false;
}


void dfs(int s, int c, int p){
    visited[s] = true;
    cc[s] = c;

    for(auto e: adj[s]){
        if(!visited[e]){
            dfs(e, c, s);
        }else{
            if(e != s && e != p){
                cc_cycles.insert(c);
            }
        }
    }

    return;
}




int main(){

    int m, n;
    cin >> m >> n;

    adj.resize(n, vector<int>());

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;

        if(b>a) swap(a, b);
        edges.insert({a,b});
    }

    for(auto p: edges){
        int a = p.first;
        int b = p.second;

        if(a != b){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }else{
            adj[a].push_back(a);
        }
    }

    // cout << "-------------\n";
    // for(int i=0; i<n; i++){
    //     for(auto e:adj[i]){
    //         cout << i+1 << " " << e+1 << "\n";
    //     }
    // }
    // cout << "-------------\n";


    for(int i=0; i<n; i++){
        bool flag_imp = false;
        if(adj[i].size() >=3){
            flag_imp = chequear_vecinos(i);
        }

        if(flag_imp){
            cout << "impossible";
            return 0;
        }

    }

    cc.resize(n, -1);
    visited.resize(n, false);

    int cc_num = 1;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i, cc_num, -1);
            cc_num++;
        }
    }


    // for(auto c: cc){
    //     cout << c << " ";
    // }cout << "\n";

    // cout << "CANT CICLOS: " << cc_cycles.size() << "\n";

    if(cc_cycles.size()>1){
        cout << "impossible";
        return 0;
    }


    map<int , vector<int>> cc_cant;
    map<int , vector<int>> cc_cant_copy;
    
    for(int i=0; i<n; i++){
        cc_cant[cc[i]].push_back(i);
    }

    for(auto kv:cc_cant){
        if((kv.second.size() == 1 && (edges.count({kv.second[0], kv.second[0]}) == 1)) || kv.second.size() > 1){
            cc_cant_copy[kv.first] = kv.second;
        }
    }

    // cout << "CANT CC REALES: " << cc_cant_copy.size() << "\n";

    if(cc_cycles.size()== 1 && cc_cant_copy.size() > 1){
        cout << "impossible";
        return 0;
    }else{
        cout << "possible";
        return 0;
    }

    return 0;
}
