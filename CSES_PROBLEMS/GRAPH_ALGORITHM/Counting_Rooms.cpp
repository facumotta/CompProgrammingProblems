#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
 
#define forn(i, n) for(tint i = 0; i < n; i++)
 
vector<vector<bool>> visited;
tint n, m;
 
void dfs(tint i, tint j){
    visited[i][j] = true;
    if(i-1 >= 0){
        if(!visited[i-1][j]){ 
            dfs(i-1, j);
        }
    }
    if(j-1 >= 0){
        if(!visited[i][j-1]){
            dfs(i, j-1);
        }
    }
    if(i+1 <= n-1){
        if(!visited[i+1][j]){ 
            dfs(i+1, j);
        }   
    }
    if(j+1 <= m-1){
        if(!visited[i][j+1]){ 
            dfs(i, j+1);
        }
    }
}
 
 
int main(){
    cin >> n >> m;
  
    visited.resize(n, vector<bool>(m, false));
    forn(i, n){
        forn(j, m){
            char k; cin >> k;
            if(k == '#') visited[i][j] = true;
        }
    }
  
  
 
    tint rooms = 0;
    
    forn(i, n){
        forn(j, m){
            if(!visited[i][j]){
                //cout << i << " " << j << endl;
                rooms++;
                dfs(i,j);
            }
        }
    }
    cout << rooms << "\n";
    
    return 0;
}
