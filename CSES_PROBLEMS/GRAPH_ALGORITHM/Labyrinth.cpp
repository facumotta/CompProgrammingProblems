#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, n) for(tint i = 0; i < n; i++)

vector<vector<char>> parent;
vector<vector<bool>> visited;
tint n, m;
bool foundPath = false;


void bfs(tint a, tint b, pair<tint, tint>& end) {
    visited[a][b] = true;
    
    queue<pair<tint, tint>> q;
    q.push({a,b});
    
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        tint i = u.first;
        tint j = u.second;

        if(i == end.first && j == end.second) foundPath = true;

        if(i-1 >= 0){
            if(!visited[i-1][j]){
                visited[i-1][j] = true;
                parent[i-1][j] = 'D';
                q.push({i-1, j});
            }
        }
        if(j-1 >= 0){
            if(!visited[i][j-1]){
                visited[i][j-1] = true;
                parent[i][j-1] = 'R';
                q.push({i, j-1});
            }
        }
        if(i+1 <= n-1){
            if(!visited[i+1][j]){ 
                visited[i+1][j] = true;
                parent[i+1][j] = 'U';
                q.push({i+1, j});
            }   
        }
        if(j+1 <= m-1){
            if(!visited[i][j+1]){ 
                visited[i][j+1] = true;
                parent[i][j+1] = 'L';
                q.push({i, j+1});
            }
        }
    }
}



int main(){
    cin >> n >> m;

    parent.resize(n, vector<char>(m, '.'));
    visited.resize(n, vector<bool>(m, false));

    pair<tint, tint> start;
    pair<tint, tint> end;
   
    forn(i, n){
        forn(j, m){
            char k;
            cin >> k;
            if(k == '#'){
              visited[i][j] = true;
              parent[i][j] = k;  
            } 
            if(k == 'A'){
                start = {i,j};
                parent[i][j] = k;
            }
            if(k == 'B'){
                end = {i,j};
                parent[i][j] = k;
            }
            
        }
    }

    bfs(start.first, start.second, end);

    if(foundPath){
        cout << "YES\n";
        tint res = 0;
        string path;
        queue<pair<tint, tint>> q;
        q.push({end.first,end.second});

        while(!q.empty()){
            auto u = q.front(); q.pop();
            tint i = u.first;
            tint j = u.second;

            if(parent[i][j] == 'A') break;

            if(parent[i][j] == 'D'){
                path.push_back('U');
                q.push({i+1, j});
                res++;
            }else if(parent[i][j] == 'U'){
                path.push_back('D');
                q.push({i-1, j});
                res++;
            }else if(parent[i][j] == 'R'){
                path.push_back('L');
                q.push({i, j+1});
                res++;
            }else{
                path.push_back('R');
                q.push({i, j-1});
                res++;
            }

        }
        cout << res << "\n";
        forn(i, path.size()) cout << path[path.size()-1-i];
    }else{
        cout << "NO\n";
    }


    return 0;
}