#include <bits/stdc++.h>

using namespace std;
typedef long long tint;
typedef pair<tint, tint> ptt;
 
tint n, m, k;
const tint INF = 1e18;
vector<vector<ptt>> adj;

class Compare {
public:
    bool operator()(ptt below, ptt above)
    {
        if (below.second > above.second) {
            return true;
        }
        else if (below.second == above.second && below.first < above.first) {
            return true;
        }
 
        return false;
    }
};

vector<tint> solve(){
    priority_queue<ptt, vector<ptt>, Compare> q;
    vector<tint> founded;
    tint max_path = -INF;
    tint paths_found = 0;
    q.push({0,0});

    while(!q.empty()){
        ptt a = q.top(); tint v = a.first; tint w_tot = a.second;
        q.pop();
        //cout << "ESTOY EN " << v << " Y HASTA ACA COSTO " << w_tot << endl;
        if(paths_found >= k && w_tot > max_path) break;
        if(v == n-1){
            founded.push_back(w_tot);
            paths_found++;
            max_path = max(max_path, w_tot);
            //cout << "encontre " << max_path << endl;
        }
        for(auto u : adj[v]){
            q.push({u.first, w_tot+u.second});
        }
    }

    sort(founded.begin(), founded.end());

    return founded;
}

 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
 
    adj.resize(n);
 
    for (tint i = 0; i < m; i++) {
        tint from, to, weight;
        cin >> from >> to >> weight;
        from--; to--;
        adj[from].push_back({to, weight});
    }
    
    vector<tint> ans = solve();
    
    for(tint i=0; i<k; i++){
        cout << ans[i] << " ";
    }cout << endl;
 
    return 0;
}