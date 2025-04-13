#include <bits/stdc++.h>

using namespace std;

/*
    O(|V| + |E|)
    KOSARAJU TIENE MISMA COMPLEJIDAD QUE TARJAN, 
    PERO ADEMAS DA EL ORDEN TOPOLOGICO DE LAS COMPONENTES
    EN CASO DE SOLO NECESITAR COMPONENTES USAR TARJAN
*/


vector<vector<int>> adj; // Lista de adyacencia del grafo original
vector<vector<int>> revAdj; // Lista de adyacencia del grafo transpuesto
vector<bool> visited; // Vector de visitados
stack<int> orderStack; // Pila de orden topológico
vector<int> component; // Componente fuertemente conexa actual

int n, m;
vector<int> roots;
vector<int> root_nodes;
vector<vector<int>> adj_scc;
vector<vector<int>> rev_adj_scc;
vector<bool> visited_root_nodes;
int edgesToAdd;

void dfsFinal(int v) {
    visited_root_nodes[v] = true;
    int recursion_calls = 0;
    for (int u : adj_scc[v]) {
        if (!visited_root_nodes[u]) {
            recursion_calls++;
            dfsFinal(u);
        }
    }
    if(recursion_calls == 0) edgesToAdd++;
}

// Función DFS para el primer recorrido del grafo
void dfs1(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }
    orderStack.push(v); // Apilar el nodo en la pila
}

// Función DFS para el segundo recorrido del grafo transpuesto
void dfs2(int v) {
    visited[v] = true;
    component.push_back(v); // Agregar el nodo a la componente actual
    for (int u : revAdj[v]) {
        if (!visited[u]) {
            dfs2(u);
        }
    }
}

// Función para encontrar las componentes fuertemente conexas del grafo
int findStronglyConnectedComponents(int n) {
    visited.assign(n, false);

    // Paso 1: Realizar el primer recorrido DFS y almacenar el orden topológico
    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            dfs1(v);
        }
    }

    // Paso 2: Transponer el grafo
    revAdj.assign(n, vector<int>());
    for (int v = 0; v < n; ++v) {
        for (int u : adj[v]) {
            revAdj[u].push_back(v);
        }
    }

    visited.assign(n, false);
    vector<vector<int>> components; // Lista de componentes fuertemente conexas

    // Paso 3: Realizar el segundo recorrido DFS en el grafo transpuesto
    while (!orderStack.empty()) {
        int v = orderStack.top();
        orderStack.pop();
        if (!visited[v]) {
            dfs2(v);
        
            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);
            components.push_back(component);

            component.clear();
        }
    }

    vector<pair<int, int>> degrees(n,{0,0}); //<E,S>

    for (int v = 0; v < n; v++)
    for (auto u : adj[v]) {
        int root_v = roots[v],
            root_u = roots[u];

        if (root_u != root_v){
            adj_scc[root_v].push_back(root_u);
            degrees[root_u].first++;
            degrees[root_v].second++;
        }
    }
    

    for(int i=0; i<components.size(); i++){
        for(int j=1; j<components[i].size(); j++){
            visited_root_nodes[components[i][j]] = true;
        }
    }

    /*
    for(int i=0; i<components.size(); i++){
        for(int j=0; j<components[i].size(); j++){
            cout << components[i][j]+1 << " ";
        }cout << endl;
    }*/
    

    if(root_nodes.size() == 1) return 0;

    int cant_din = 0;
    int cant_dout = 0;
    for(int i=0; i<n; i++){
        if(!visited_root_nodes[i]){
            if(degrees[i].first == 0){
                cant_din++;
            }
            if(degrees[i].second == 0){
                cant_dout++;
            }
        } 
    }
    
    return max(cant_din, cant_dout);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    adj.resize(n, vector<int>());
    revAdj.resize(n, vector<int>());
    
    roots.resize(n, 0);
    adj_scc.resize(n, vector<int>());
    visited_root_nodes.resize(n, false);

    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;
        from--; to--;
        adj[from].push_back(to);
        revAdj[to].push_back(from);
    }

    int res = findStronglyConnectedComponents(n);
    cout << res << "\n";
    /*
    for(int i=0; i<components.size(); i++){
        for(int j=0; j<components[i].size(); j++){
            cout << components[i][j]+1 << " ";
        }cout << endl;
    }
    */

    return 0;
}