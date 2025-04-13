
#include <bits/stdc++.h>
 
using namespace std;
 
long long n, f, b;
vector<vector<long long>> adj;
 
vector<bool> visited;
vector<bool> visited_b;
vector<bool> visited_f;
vector<long long> comp_b;
vector<long long> comp_f;
vector<long long> tin, low;
long long timer;
 
void dfs_normal(long long v, long long comp_num, long long vertice_feo, vector<bool> &visited2, vector<long long> &comp){
    visited2[v] = true;
    comp[v] = comp_num;
    for(auto u:adj[v]){
        if(visited2[u] || (u == vertice_feo)) continue;
        dfs_normal(u, comp_num, vertice_feo, visited2, comp);
    }
 
 
}
bool f_CUTPOINT = false;
bool b_CUTPOINT = false;
 
void dfs(long long v, long long p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    long long children=0;
    for (long long to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1){
                if(v == f){
                    f_CUTPOINT = true;
                }else if(v == b){
                    b_CUTPOINT = true;
                }
            }
            ++children;
        }
    }
    if(p == -1 && children > 1){
        if(v==f){
            f_CUTPOINT = true;
        }else if(v == b){
            b_CUTPOINT = true;
        }
    }
}
 
void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (long long i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
 
 
int main(){
 
    cin >> n >> f >> b;
    f--; b--;

    if(n == 1){ 
        cout << 0;
        return 0;
    }
    
    adj.assign(n, vector<long long>());
    for(long long i=0; i<n-1; i++){
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    //find_cutpoints();
 
    comp_b.assign(n,-1);
    comp_f.assign(n,-1);
    visited_b.assign(n,false);
    visited_f.assign(n,false);
 
    //cout << "ALSDLASDLAS"<< endl;
    //Calculo #f_b
    long long comp_num = 1;
    for(long long i=0; i<n; i++){
        if(i == f || visited_f[i]){
            comp_num--;
        }else if(visited_f[i] == false){
            dfs_normal(i, comp_num, f, visited_f, comp_f);
        }
        comp_num++;
    }
    long long card_f_b_comp = 0;
    for(long long i = 0; i<n; i++){
        if(comp_f[i] == comp_f[b]){
            card_f_b_comp++;
        }
    }
    /*
    for(long long i=0; i<n; i++){
        cout << comp_f[i] << " ";
    }cout << endl;
    */
    //Calculo #b_f
    comp_num = 1;
    for(long long i=0; i<n; i++){
        if(i == b || visited_b[i]){
            comp_num--;
        }else if(visited_b[i] == false){
            dfs_normal(i, comp_num, b, visited_b, comp_b);
        }
        comp_num++;
    }
    long long card_b_f_comp = 0;
    for(long long i = 0; i<n; i++){
        if(comp_b[i] == comp_b[f]){
            card_b_f_comp++;
        }
    }
    /*
    for(long long i=0; i<n; i++){
        cout << comp_b[i] << " ";
    }cout << endl;
    
    cout << "#f_b " << card_f_b_comp << endl;
    cout << "#b_f " << card_b_f_comp << endl;
    */

    cout << n*(n-1) - (n-card_f_b_comp)*(n-card_b_f_comp);
    return 0;

    if(f_CUTPOINT && b_CUTPOINT){
        cout << n*(n-1) - (n-card_f_b_comp)*(n-card_b_f_comp);
    }else if(f_CUTPOINT && (!(b_CUTPOINT))){
        cout << n*(n-1) - (n-card_f_b_comp);
    }else if(b_CUTPOINT && (!(f_CUTPOINT))){
        cout << n*(n-1) - (n-card_b_f_comp);
    }else{
        cout << n*(n-1) - 1;
    }
 
}