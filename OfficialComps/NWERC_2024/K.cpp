#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;


ll n, m, k;
const ll INF = 1e18;
vector<vpll> adj;
vll dist_0;
vll dist_n;
vector<bool> processed;
vpll final_dist;
vector<long double> probas;

void dijkstra(ll x, vll & dist){
    priority_queue<pair<ll,ll>> q;
    for (ll i = 0; i < n; i++) dist[i] = INF;
    dist[x] = 0; q.push({0,x});
    
    while (!q.empty()) {
        ll a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
      
        for (auto u : adj[a]) {
            ll b = u.first, w = u.second;
        
            if (dist[a]+w < dist[b]) {
                dist[b] = dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }
 }




int main(){

    cin >> n >> m >> k;

    dist_0.resize(n, INF);
    dist_n.resize(n, INF);
    processed.resize(n, false);
    final_dist.resize(n);
    adj.resize(n, vpll());
    probas.resize(n);


    for(ll i = 0; i<m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    bool flag = false;

    for(ll i = 0; i<k; i++){
        ll nodo;
        long double p;
        cin >> nodo >> p;
        nodo--;
        probas[nodo] = p;
        if(p == 1.0) flag = true;
    }

    // for(auto pr: probas){
    //     cout <<  pr << " ";
    // }cout << "\n";

    if(!flag){
        cout << "impossible";
        return 0;
    }

    dijkstra(0, dist_0);
    processed.assign(n, false);
    dijkstra(n-1, dist_n);



    for(ll i = 0; i<n; i++){
        final_dist[i].second = i;
        final_dist[i].first = dist_0[i] + dist_n[i];
    }

    // cout << "-------\n";
    // for(auto p: final_dist){
    //     cout << p.first << " " << p.second << "\n";
    // }


    sort(final_dist.begin(), final_dist.end());


    vector<long double> temp(n);

    for(ll i = 0; i<n; i++){
        temp[i] = probas[final_dist[i].second];
    }
    probas = temp;

    long double acum_neg = 1;
    long double res = 0;
    for(ll i = 0; i<n; i++){
        long double proba_casito = probas[i];
        res +=  final_dist[i].first * (proba_casito * acum_neg);
        acum_neg *= (1-proba_casito);
    }

    cout << fixed << setprecision(10) << res;

    return 0;
}