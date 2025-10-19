#include <bits/stdc++.h>

using namespace std;
typedef long long tint;

vector<vector<tint>> adj;
vector<tint> requirements;
vector<tint> course;
vector<bool> visitado;
tint n, m;

void bfs(tint s) {
    visitado[s] = true;
    queue<tint> q;
    q.push(s);
    while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto v : adj[u]) {
            if (visitado[v]) continue;
            visitado[v] = true;
            course.push_back(v);
            q.push(v);
        }
    }
}


int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin >> n >> m;

    adj.resize(n+1);
    requirements.resize(n+1, 0);
    visitado.resize(n+1, false);

    for (tint i = 0; i < m; i++) {
        tint from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        requirements[to]++;
    }

    for(tint i = 1; i<=n; i++){
        if(requirements[i] == 0){
            adj[0].push_back(i);
        }
    }

    bfs(0);
    bool visited_all = true;
    for(tint i = 0; i<=n; i++){
        if(!visitado[i]){
            visited_all == false;
        }
    }


    if(visited_all){
        for(int i=0; i<course.size(); i++){
            cout << course[i] << " ";
        }cout << endl;
    }else{
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}