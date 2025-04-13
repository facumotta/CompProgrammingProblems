#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tint t; cin >> t;
    for(tint j=0; j<t; j++){    
        string s; cin >> s;

        bool flag_print = true;
        stack<tint> simulation;
        bool esta_ord = false;
        tint ord_hasta = -1;
        bool esta_desord = false;
        tint desor_hasta = -1;
        bool no_idea = true;
        tint query = 0;

        for(auto c:s){
            if(c == '+'){
                simulation.push(0);
                if(esta_ord && simulation.size() >= 2){
                    esta_ord = false;
                    no_idea = true;
                }else if(esta_desord){
                    continue;
                }else{
                    //Caso no_idea
                    continue;
                }
            }else if(c == '-'){
                simulation.pop();
                if(esta_ord && simulation.size()+1 == ord_hasta){
                    ord_hasta--;
                }else if(esta_desord){
                    esta_desord = false;
                    no_idea = true;
                    if(desor_hasta == simulation.size()+1){
                        desor_hasta = -1;
                    }else{
                        continue;
                    }
                }else{
                    //Caso no_idea
                    continue;
                }
            }else{
                if(c == '1'){
                    query++;
                    if(simulation.size() == 0 || simulation.size() == 1){
                        continue;
                    }else if(query == 1){
                        no_idea = false;
                        esta_ord = true;
                        ord_hasta = simulation.size();
                    }else {
                        if(esta_ord){
                            continue;
                        }else if(esta_desord){
                            cout << "NO\n";
                            flag_print = false;
                            break;
                        }else{
                            //Caso no_idea
                            if(simulation.size() == desor_hasta){
                                cout << "NO\n";
                                flag_print = false;
                                break;  
                            }else{
                                no_idea = false;
                                esta_ord = true;
                                ord_hasta = simulation.size();
                            }
                        }
                    }
                }else{ // Caso query 0
                    query++;
                    if(simulation.size() == 0 || simulation.size() == 1){
                        cout << "NO\n";
                        flag_print = false;
                        break;
                    }else if(query == 1){
                        no_idea = false;
                        esta_desord = true;
                        desor_hasta = simulation.size();
                    }else {
                        if(esta_ord){
                            cout << "NO\n";
                            flag_print = false;
                            break;
                        }else if(esta_desord){
                            continue;
                        }else{
                            //Caso no_idea
                            if(simulation.size() == ord_hasta){
                                cout << "NO\n";
                                flag_print = false;
                                break;  
                            }else{
                                no_idea = false;
                                esta_desord = true;
                                desor_hasta = simulation.size();
                            }
                        }
                    }
                }
            }
        }

        if(flag_print){
            cout << "YES\n";
        }
    
    }
}
