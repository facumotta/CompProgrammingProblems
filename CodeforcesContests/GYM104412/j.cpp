#include <bits/stdc++.h>

using namespace std;

//typedef tint long long;

vector<vector<int>> adj;
vector<pair<int,int>> queries;

set<pair<int,int>> bridges;
int N, M, Q; 
vector<bool> visited;
vector<int> tin, low;
int timer;

vector<vector<int>> adj_cc;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges.insert({v,to});
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(N, false);
    tin.assign(N, -1);
    low.assign(N, -1);
    for (int i = 0; i < N; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

vector<bool> visited_adj_cc;
vector<int> cc_number;

void dfs_2(int s, int cc){
    cc_number[s] = cc;
    visited_adj_cc[s] = true;

    for(auto e: adj_cc[s]){
        if(!(visited_adj_cc[e])){
            dfs_2(e, cc);
        }
    }

}



vector<vector<int>> final_adj;
vector<bool> visited_final_adj;
map<int, int> counting_cc;
map<int, vector<int>> cc_nodes;



void special_dfs(int s){
    visited_final_adj[s] = true;

    for(auto e: adj[s]){
        if((!(visited_final_adj[e])) && (cc_number[e] == cc_number[s])){
            special_dfs(e);
        }else if((!(visited_final_adj[e])) && (cc_nodes[cc_number[s]].size() == 1)){
            cc_number[e] = cc_number[s];
            special_dfs(e);
        }
    }

}




void solve(){

    find_bridges();
    // cout << "---------------------------------------\n";
    // cout << "PUENTES: \n";
    // for(auto p: bridges){
    //     cout << p.first << " " << p.second << "\n";
    // }
    // cout << "---------------------------------------\n";
    adj_cc.resize(N, vector<int>());

    for(int u=0; u<N; u++){
        for(int v : adj[u]){

            if((bridges.count({u,v})!=0) || (bridges.count({v,u}) != 0)){
                continue;
            }else{
                adj_cc[u].push_back(v);
            }
        }
    }
    
    // cout << "GRAFO SIN PUENTES: \n";

    // for(int u=0; u<N; u++){
    //     for(int v : adj_cc[u]){
    //             cout << u << " " << v << "\n";
    //     }
    // }
    

    // cout << "---------------------------------------\n";

    cc_number.resize(N, 0);
    visited_adj_cc.resize(N, false);

    int number_of_cc = 0;

    for(int i=0; i<N; i++){
        if(!(visited_adj_cc[i])){
            dfs_2(i, i);
            number_of_cc++;
        }
    }

    // cout << "CC para cada nodo: \n";


    // for(auto k: cc_number)
    //     cout << k << " ";

    // cout << "\n---------------------------------------\n";


    for(int i=0; i<N; i++){
        cc_nodes[cc_number[i]].push_back(i);
    }

    final_adj.resize(N, vector<int>());

    for(auto p:bridges){
        int nuevo_u = cc_number[p.first]; 
        int nuevo_v = cc_number[p.second];
        final_adj[nuevo_u].push_back(nuevo_v);
    }

    // cout << "FINAL ADJ: \n";
    // for(int u=0; u<N; u++){
    //     for(auto v : final_adj[u]){
    //             cout << u << " " << v << "\n";
    //     }
    // }
    

    // cout << "---------------------------------------\n";


    visited_final_adj.resize(N, false);

    for(int i=0; i<N; i++){
        if(!(visited_final_adj[i])){
            special_dfs(i);
        }
    }


    // cout << "CC para cada nodo: \n";


    // for(auto k: cc_number)
    //     cout << k << " ";

    // cout << "\n---------------------------------------\n";
    // cout << "CANT NODOS: \n";

    // for(int i=0; i<N; i++)
    //     cout << cc_nodes[cc_number[i]].size() << " ";

    // cout << "\n---------------------------------------\n";

    return;
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> Q;

    adj.resize(N, vector<int>());

    for(int i=0; i<M; i++){
        int u,v; cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    for(int i=0; i<Q; i++){
        int u,v; cin >> u >> v;
        queries.push_back({u-1,v-1});
    }


    solve();

    // cout << "---------------------------------------\n";
    // cout << "---------------------------------------\n";
    // cout << "RESPONDIENDO: \n";

    for(auto q:queries){
        // cout << "Query: " << q.first+1 << " " << q.second+1 << "\n";
        int a = cc_nodes[cc_number[q.first]].size();
        int b = cc_nodes[cc_number[q.second]].size();
        // cout << "Res: " << a << " " << b << "\n";
        if((a == 1 && b == 1) && (cc_number[q.first] == cc_number[q.second])){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }


    return 0;
}