#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
 
using namespace std;

struct triplaState{
    int valor;
    int max_izq;
    int max_der;
};

bool comparar(triplaState a, triplaState b){
    if(a.valor == b.valor){
        if(a.max_izq == b.max_izq){
            return a.max_der > b.max_der;
        }else{
            return a.max_izq > b.max_izq;
        }
    }
    return a.valor < b.valor;
}



int main(){
    int t; cin >> t;

    for(int test = 0; test<t; test++){
        int n; cin >> n;
        
        triplaState vacio;
        vacio.valor = 0;
        vacio.max_der = 0;
        vacio.max_izq = 0;

        vector<triplaState> estados(n+1, vacio);
        vector<vector<int>> regalos(n+1, vector<int>(3,0));
        for(int i=1; i<=n; i++){
            cin >> regalos[i][1] >> regalos[i][2];
        }  
        int maximoTodoIzq = max(regalos[1][1], regalos[2][1]);
        int maximoTodoDer = max(regalos[1][2], regalos[2][2]); 
        //cout << "----------------\n";
        for(int k=2; k<=n; k++){
            if(k==2){
                if(abs(regalos[1][1]-regalos[2][2]) < abs(regalos[1][2]-regalos[2][1])){
                    triplaState estadoNuevo;
                    estadoNuevo.valor = abs(regalos[1][1]-regalos[2][2]);
                    estadoNuevo.max_izq = regalos[1][1];
                    estadoNuevo.max_der = regalos[2][2];
                    estados[k] = estadoNuevo;
                }else{
                    triplaState estadoNuevo;
                    estadoNuevo.valor = abs(regalos[1][2]-regalos[2][1]);
                    estadoNuevo.max_izq = regalos[2][1];
                    estadoNuevo.max_der = regalos[1][2];
                    estados[k] = estadoNuevo;
                }
            }else{

                triplaState agarroIzq = estados[k-1];
                agarroIzq.max_izq = max(agarroIzq.max_izq, regalos[k][1]);
                agarroIzq.valor = abs(agarroIzq.max_izq - agarroIzq.max_der);

                triplaState agarroDer = estados[k-1];                
                agarroDer.max_der = max(agarroDer.max_der, regalos[k][2]);
                agarroDer.valor = abs(agarroDer.max_izq - agarroDer.max_der);
                
                triplaState todoIzq;
                maximoTodoIzq = max(maximoTodoIzq, regalos[k-1][1]);
                todoIzq.max_izq = maximoTodoIzq;
                todoIzq.max_der = regalos[k][2];
                todoIzq.valor = abs(todoIzq.max_der - todoIzq.max_izq);
                
                triplaState todoDer;
                maximoTodoDer = max(maximoTodoDer, regalos[k-1][2]);
                todoDer.max_der = maximoTodoDer;
                todoDer.max_izq = regalos[k][1];
                todoDer.valor = abs(todoDer.max_der - todoDer.max_izq);
                
                vector<triplaState> posiblesStates = {agarroIzq, agarroDer, todoIzq, todoDer};
                sort(posiblesStates.begin(),posiblesStates.end(),comparar);
                /*
                cout << "k=" << k << "\n";
                cout << "maximo der hasta fila k-1: " << maximoTodoDer << "\n";
                cout << "maximo izq hasta fila k-1: " << maximoTodoIzq << "\n";
                
                cout << "---------\n";
                cout << "posibles estados\n";
                cout << "valor de k: " << k << "\n";
                cout << agarroIzq.max_izq << " " << agarroIzq.max_der << " " << agarroIzq.valor << "\n";
                cout << agarroDer.max_izq << " " << agarroDer.max_der << " " << agarroDer.valor << "\n";
                cout << todoIzq.max_izq << " " << todoIzq.max_der << " " << todoIzq.valor << "\n";
                cout << todoDer.max_izq << " " << todoDer.max_der << " " << todoDer.valor << "\n";
                cout << "---------\n";
                */
                estados[k] = posiblesStates[0];
            }
            //cout << "k vale " << k << "| "<< estados[k].max_izq << " " << estados[k].max_der << " " << estados[k].valor << "\n";
        }
        cout << estados[n].valor << "\n";
    }

    return 0;
}
