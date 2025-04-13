#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
 
using namespace std;
 
int n;
int x;
vector<int> coins;
vector<vector<int>> states;
int MOD = 1e9+7;
 
vector<long long> dp(1000001);
 
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) { cin >> coins[i]; }
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int weight = 0; weight <= x; weight++) {
			if (weight - coins[i - 1] >= 0) {
				dp[weight] += dp[weight - coins[i - 1]];
                while(dp[weight] > MOD){
                    dp[weight] -= MOD;
                }
			}
		}
	}
	cout << dp[x]%MOD << '\n';
    return 0;
}