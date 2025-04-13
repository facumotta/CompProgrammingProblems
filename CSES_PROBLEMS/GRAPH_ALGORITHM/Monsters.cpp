#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, n) for(tint i = 0; i < n; i++)

vector<vector<char>> parent;
vector<vector<bool>> visitedA;
vector<vector<bool>> visitedMonsters;
vector<vector<tint>> distA;
vector<vector<tint>> distMonsters;
tint n, m;
tint INF = 1e12;
bool foundPath = false;
set<pair<tint, tint>> borde;
set<pair<tint, tint>> monsters;
pair<tint, tint> start;

queue<pair<tint, tint>> q;

void bfs(vector<vector<bool>>& visited, vector<vector<tint>>& dist, bool bfsNormal) {
    
    if(bfsNormal){
        visited[start.first][start.second] = true;
        dist[start.first][start.second] = 0;
        q.push(start);
    }

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        tint i = u.first;
        tint j = u.second;

        if(i-1 >= 0){
            if(!visited[i-1][j]){
                visited[i-1][j] = true;
                dist[i-1][j] = dist[i][j] + 1;
                if(bfsNormal){
                    parent[i-1][j] = 'D';
                }
                q.push({i-1, j});
            }
        }

        if(j-1 >= 0){
            if(!visited[i][j-1]){
                visited[i][j-1] = true;
                dist[i][j-1] = dist[i][j] + 1;
                if(bfsNormal){
                    parent[i][j-1] = 'R';
                }
                q.push({i, j-1});
            }
        }

        if(i+1 <= n-1){
            if(!visited[i+1][j]){ 
                visited[i+1][j] = true;
                dist[i+1][j] = dist[i][j] + 1;
                if(bfsNormal){
                    parent[i+1][j] = 'U';
                }

                q.push({i+1, j});
            }   
        }

        if(j+1 <= m-1){
            if(!visited[i][j+1]){ 
                visited[i][j+1] = true;
                dist[i][j+1] = dist[i][j] + 1;
                if(bfsNormal){
                    parent[i][j+1] = 'L';
                }
                q.push({i, j+1});
            }
        }
    }
}

void bfsPrincipal(set<pair<tint, tint>>& monsters, vector<vector<bool>>& visited, vector<vector<tint>>& distancia){
    for(auto m : monsters){
        visited[m.first][m.second] = true;
        distMonsters[m.first][m.second] = 0;
        q.push({m.first, m.second});
    }

    bfs(visited, distancia, false);
}



int main(){
    cin >> n >> m;

    parent.resize(n, vector<char>(m, '.'));
    distA.resize(n, vector<tint>(m, INF));
    distMonsters.resize(n, vector<tint>(m, INF));
    visitedA.resize(n, vector<bool>(m, false));
    visitedMonsters.resize(n, vector<bool>(m, false));


    forn(i, n){
        forn(j, m){
            char k;
            cin >> k;
            if(k == '#'){
                visitedA[i][j] = true;
                visitedMonsters[i][j] = true;
                distA[i][j] = INF;
                distMonsters[i][j] = INF;
                parent[i][j] = k;  
            }
            if(k == 'M'){
                visitedA[i][j] = true;
                distA[i][j] = INF;
                monsters.insert({i, j});
                parent[i][j] = k;  
            } 
            if(k == 'A'){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    borde.insert({i, j});
                }
                start = {i,j};
                parent[i][j] = k;
            }
            if(k == '.' && (i == 0 || i == n-1 || j == 0 || j == m-1)){
                borde.insert({i, j});
                parent[i][j] = k;
            }   
        }
    }


    bfsPrincipal(monsters, visitedMonsters, distMonsters);

    bfs(visitedA, distA, true);

    pair<tint, tint> exit = {-1, -1};
    pair<tint, tint> flag = {-1, -1};
    for(auto c : borde){
        if(distA[c.first][c.second] < distMonsters[c.first][c.second] && distA[c.first][c.second] != -1){
            exit = c; 
        }
    }

    if(exit != flag){
        cout << "YES\n";
        tint res = 0;
        string path;
        queue<pair<tint, tint>> q2;
        q2.push({exit.first, exit.second});

        while(!q2.empty()){
            auto u = q2.front(); q2.pop();
            tint i = u.first;
            tint j = u.second;

            if(parent[i][j] == 'A') break;

            if(parent[i][j] == 'D'){
                path.push_back('U');
                q2.push({i+1, j});
                res++;
            }else if(parent[i][j] == 'U'){
                path.push_back('D');
                q2.push({i-1, j});
                res++;
            }else if(parent[i][j] == 'R'){
                path.push_back('L');
                q2.push({i, j+1});
                res++;
            }else{
                path.push_back('R');
                q2.push({i, j-1});
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