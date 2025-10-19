#include <bits/stdc++.h>
 
using namespace std;
typedef long long tint;
 
#define forn(i, n) for(tint i = 0; i < n; i++)

tint n, m, q;
tint INF = 1e18;
vector<vector<tint>> dist;
 
int main() {
    cin >> n >> m >> q;
 
    dist.resize(n, vector<tint>(n, INF));

    for (tint i = 0; i < m; i++) {
        tint from, to, weight;
        cin >> from >> to >> weight;
        from--; to--;
        if(dist[to][from] > weight){
            dist[to][from] = weight;
            dist[from][to] = weight;
        }
    }

    //Floyd-Warshall    
    for (tint k = 0; k < n; k++) {
        for (tint i = 0; i < n; i++) {
            for (tint j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    forn(l, q){
        tint a, b;
        cin >> a >> b;
        a--; b--;
        if(dist[a][b] == INF){
            cout << "-1\n";
        }else if(a == b){
            cout << "0\n";
        }else{
            cout << dist[a][b] << "\n";
        }
    }
 
    return 0;
}