#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;





int main(){

    int a, b;
    char slash;

    cin >> a >> slash >> b;

    if(a<b){
        if(a == b-1){
            cout << b << " " << a << "\n";
            for(int i=2; i<=a+1; i++){
                cout << 1 << " " << i << "\n";
            }
        }else{
            cout << "impossible\n";
        }
    }else if(a==b){
        cout << 3 << " " << 2 << "\n";
        cout << 1 << " " << 2 << "\n";
        cout << 2 << " " << 3 << "\n";
    }else{
        int k= a/b;

        vector<int> nodes(2*k+2, 1);

        nodes[k+1] = 2*k+2;

        int sum = 2*k+3+2*k;

        while(sum%b != 0){
            nodes[k+1]++;
            sum++;
        }


        // for(auto l:nodes){
        //     cout << l << " ";
        // }cout << "\n";


        int n = sum;
        int p = n - 2*k-1;
        int s = n/b;

        int precalc_izq = 2*k*k+2*k+(k+1)*p;
        int precalc_der = a*s;

        // cout << "IZQ: " << precalc_izq << "\n";
        // cout << "DER: " << precalc_der << "\n";
        int idx = 2*k+1;
        while(precalc_izq != precalc_der){
            if(precalc_izq > precalc_der){
                if(nodes[idx] >= 1){
                    precalc_izq--;
                    nodes[idx]--;
                    nodes[idx-1]++;
                }else{
                    idx--;
                }
            }else if(precalc_izq < precalc_der){
                if(nodes[k+1] > 1){
                    precalc_izq++;
                    nodes[k+1]--;
                    nodes[k+2]++;
                }else{
                    k++;
                }
            }
        }

        vector<pair<int, int>> edges;
        int from_index = 1;
        int to_index = 1;
        for(int i=0; i<nodes.size()-1; i++){
            for(int j=0; j<nodes[i+1]; j++){
                to_index++;
                edges.push_back({from_index, to_index});
            }

            from_index = to_index;
        }

        // for(auto l:nodes){
        //     cout << l << " ";
        // }cout << "\n";

        cout << n << " " << edges.size() << "\n";
        for(auto e:edges){
            cout << e.first << " " << e.second << "\n";
        }



    }

    return 0;
}