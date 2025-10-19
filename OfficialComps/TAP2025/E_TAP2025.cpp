#include<bits/stdc++.h>
using namespace std;

typedef long long tint;

vector<vector<tint>> adj;

vector<tint> soldiers;
vector<bool> visitado;
tint N;
vector<tint> nodo_dist_1;
vector<pair<tint, tint>> final_order;

struct LCA {
    vector<tint> height, euler, first, segtree;
    vector<bool> visited;
    tint n;

    LCA(vector<vector<tint>> &adj, tint root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        tint m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<tint>> &adj, tint node, tint h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(tint node, tint b, tint e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            tint mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            tint l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    tint query(tint node, tint b, tint e, tint L, tint R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        tint mid = (b + e) >> 1;

        tint left = query(node << 1, b, mid, L, R);
        tint right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    tint lca(tint u, tint v) {
        tint left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};



pair<tint, tint> find_min_in_cc(tint s, vector<vector<tint>> &adj, LCA &lca_adj) {
    map<tint, pair<tint, vector<tint>>> soldiers_height;
    visitado[s] = true;
    soldiers_height[lca_adj.height[s]] = {soldiers[s], {s}};
    queue<tint> q;
    q.push(s);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (visitado[v]) continue;
            if(soldiers[v] != 0){
                soldiers_height[lca_adj.height[v]].first += soldiers[v];
                soldiers_height[lca_adj.height[v]].second.push_back(v);
            }
            visitado[v] = true;
            q.push(v);
        }
    }


    tint max_sold = soldiers[s];
    tint best_time = 1;

    for(auto h:soldiers_height){

        if(h.second.first > max_sold){
            tint padre = h.second.second[0];
            for(auto v: h.second.second){
                padre = lca_adj.lca(padre, v);            
            }

            max_sold = h.second.first;
            best_time = h.first - lca_adj.height[padre] + 1;            
        }else if (h.second.first == max_sold){
            tint padre = h.second.second[0];
            for(auto v: h.second.second){
                padre = lca_adj.lca(padre, v);            
            }

            best_time = min(best_time, h.first - lca_adj.height[padre] + 1);            
        }
    }


    return {max_sold, best_time};
}


void solve(){
    
    LCA lca_adj(adj, 0);

    visitado.assign(N, false);
    visitado[0] = true;

    tint best_sold = -1;
    tint best_time = 10e6;

    for(tint i=0; i<adj.size(); i++){
        if(lca_adj.height[i] == 1){
            pair<tint, tint> cc_best = find_min_in_cc(i, adj, lca_adj);

            if(cc_best.first > best_sold){
                best_sold = cc_best.first;
                best_time = cc_best.second;
            }else if(cc_best.first == best_sold){
                best_time = min(best_time, cc_best.second);
            }
        }
    }

    cout << best_sold << " " << best_time;

    return;
}





int main(){

    cin >> N;
    
    adj.resize(N);
    soldiers.resize(N);


    for(tint i=1; i<N; i++){
        cin >> soldiers[i];
    }

    for(tint i=0; i<N-1; i++){
        tint u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);

    }

    solve();

    return 0;
}