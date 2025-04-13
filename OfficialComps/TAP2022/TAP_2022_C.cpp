#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
using tint = long long;

vector<vector<char>> tablero;
vector<vector<bool>> visited;
map<int, int> comp_conex;


void bfs(int i, int j, int cc){
    visited[i][j] = true;
    if(tablero[i][j] == 'C') comp_conex[cc]++;

    queue<pair<int, int>> q;
    q.push({i,j});

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        if(tablero[u.first][u.second] == 'C') comp_conex[cc]++;

        if(u.first-1 >= 0){
            if(!visited[u.first-1][u.second]){
                visited[u.first-1][u.second] = true;
                q.push({u.first-1, u.second});
            }
        }
        if(u.second-1 >= 0){
            if(!visited[u.first][u.second-1]){
                visited[u.first][u.second-1] = true;
                q.push({u.first, u.second-1});
            }
        }
        if(u.first+1 <= visited.size()-1){
            if(!visited[u.first+1][u.second]){ 
                visited[u.first+1][u.second] = true;
                q.push({u.first+1, u.second});
            }
        }
        if(u.second+1 <= visited[0].size()-1){
            if(!visited[u.first][u.second+1]){ 
                visited[u.first][u.second+1] = true;
                q.push({u.first, u.second+1});
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<pair<int, int>> cuts;
    int max_x = 0;
    int max_y = 0;
    for(int i=0; i<n+1; i++){
        int a, b; cin >> a >> b;
        if(max_x < a){
            max_x = a;
        }
        if(max_y < b){
            max_y = b;
        }
        cuts.push_back({a,b});
    }

    tablero.resize((2*(max_y+1)+1), vector<char>((2*(max_x+1)+1), 'B'));
    visited.resize((2*(max_y+1)+1), vector<bool>((2*(max_x+1)+1), false));

    for(int i=0; i<(max_y+1); i++){
        for(int j=0; j<(max_x+1); j++){
            tablero[2*i+1][2*j+1] = 'C';
        }
    }

    for(int i=0; i<n; i++){
        if(cuts[i].first == cuts[i+1].first){
            int m = min(cuts[i].second, cuts[i+1].second);
            int M = max(cuts[i].second, cuts[i+1].second);
            for(int k=(2*m); k<=(2*M); k++){
                visited[k][2*cuts[i].first] = true;
                
            }
        }else{
            int m = min(cuts[i].first, cuts[i+1].first);
            int M = max(cuts[i].first, cuts[i+1].first);
            for(int k=(2*m); k<=(2*M); k++){
                visited[2*cuts[i].second][k] = true;
                
            }
        }
    }
   
    int cc = 0;
    for(int i=0; i<(2*(max_y+1)+1); i++){
        for(int j=0; j<(2*(max_x+1)+1); j++){
            if(!visited[i][j]){
                bfs(i, j, cc);
                cc++;
            }
        }
    }
    

    int res = 0;
    for(auto c:comp_conex){
        if(c.first == 0) continue;
        if(c.second-1 > res) res = c.second-1;
    }
    cout << res << "\n";

    return 0;
}