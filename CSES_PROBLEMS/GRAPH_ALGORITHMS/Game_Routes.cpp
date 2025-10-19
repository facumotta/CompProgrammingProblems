#include <bits/stdc++.h>
 
using namespace std;
typedef long long tint;
 
vector<vector<int>> adj;
tint n, m, res;
tint MOD = 1e9+7;
 
void bfs(int s) {
    stack<int> q;
    q.push(s);
    
    while (!q.empty()) {
        auto u = q.top(); q.pop();
        for (auto v : adj[u]) {
            if(v == n-1) res++;
            if(res > MOD) res = res%MOD;
            q.push(v);
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin >> n >> m;
    res = 0;
    adj.resize(n);
 
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        from--; to--;
        adj[from].push_back(to);
    }
 
    bfs(0);
 
    cout << res%MOD << "\n";
 
    return 0;
}
