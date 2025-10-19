#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> adj;

vector<bool> visited;
vector<int> heights;
vector<int> lefts;
vector<int> rights;
vector<int> parents;
vector<int> heights_req;


const int INF = 1e9;

int dfs(int s){
    visited[s] = true;
    heights[s] = 0;

    for(auto e:adj[s]){
        if(!visited[e]){
            heights[s] = max(heights[s], dfs(e) +1);
            
            parents[e] = s;
            if(lefts[s] == INF) lefts[s] = e;
            else rights[s] = e;
            
        }
    }

    return heights[s];

}

void dfs_req(int s){
    visited[s] = true;

    if(s != 0){
        if(s == lefts[parents[s]]){
            //Es hijo izquierdo
            if(rights[parents[s]] == INF) heights_req[s] = min({heights[s], 0, heights_req[parents[s]]-1});
            else heights_req[s] = min({heights[s], heights[rights[parents[s]]] + 1, heights_req[parents[s]]-1});
        }else{
            //Es hijo derecho
            if(lefts[parents[s]] == INF) heights_req[s] = min({heights[s], 0, heights_req[parents[s]]-1});
            else heights_req[s] = min({heights[s], heights[lefts[parents[s]]] + 1, heights_req[parents[s]]-1});
        }
    }

    for(auto e:adj[s]){
        if(!visited[e]){
            dfs_req(e);
        }
    }

    // cout << "volviendo de nodo: "<< s+1 << "\n";

    if(lefts[s] == INF && rights[s] == INF){
        heights[s] = 0;
    }else{
        if(lefts[s] == INF && heights_req[rights[s]] < 0){
            heights[s] = 0;
        }else if(rights[s] == INF && heights_req[lefts[s]] < 0){
            heights[s] = 0;
        }else{
            if(lefts[s] == INF) heights[s] = heights[rights[s]] + 1;
            else if(rights[s] == INF) heights[s] = heights[lefts[s]] + 1;
            else if(heights_req[lefts[s]] < 0 && heights_req[rights[s]] < 0) heights[s] = 0;
            else heights[s] = max(heights[lefts[s]], heights[rights[s]]) + 1;
        }
    }


    return;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);       
    int n;
    cin >> n;

    adj.resize(n, vector<int>());
    visited.resize(n, false);
    heights.resize(n, 0);
    heights_req.resize(n, 0);
    lefts.resize(n, INF);
    rights.resize(n, INF);
    parents.resize(n, INF);

    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);


    // cout << "alturas: ";
    // for(auto h:heights){
    //     cout << h << " ";
    // }cout << "\n";

    // cout << "padres: ";
    // for(auto h:parents){
    //     cout << h << " ";
    // }cout << "\n";

    // cout << "izq: ";
    // for(auto h:lefts){
    //     cout << h << " ";
    // }cout << "\n";

    // cout << "der: ";
    // for(auto h:rights){
    //     cout << h << " ";
    // }cout << "\n";

    for(int i=0; i<log2(n); i++){
        visited.assign(n, false);
        heights_req.assign(n , 0);
        heights_req[0] = heights[0];
        dfs_req(0);        
    }

    int ans = 0;

    // cout << "req_heights: ";
    for(auto h:heights_req){
        // cout << h << " ";
        if(h<0) ans++;
    }// cout << "\n";

    // cout << "----------\n";
    // cout << "NUEVAS ALTURAS: \n";
    // for(auto h:heights){
    //     cout << h << " ";
    // }cout << "\n";

    cout << ans;

    return 0;
}