#include <bits/stdc++.h>
using namespace std;

typedef long long tint;

tint power(tint a, tint b)
{

    tint res = 1;
    while (b > 0) {

        if (b & 1) {
            res = (res * a);
        }


        a = (a * a);
        b >>= 1;
    }
    return res;
}

tint findDigit(tint N)
{
    tint digits = 1;

    tint base = 9;

    while (N - digits * base > 0) {
        N -= digits * base;
        base *= 10;
        digits++;
    }
    tint index = N % digits;

    tint res
        = power(10, (digits - 1)) + (N - 1) / digits;


    if (index != 0)
        res = res / power(10, digits - index);
    return res % 10;
}


int main()
{
    tint t; cin >> t;

    for (int i = 0; i < t; i++){
        tint k; cin >> k;
        cout << findDigit(k) << "\n";
    }

    return 0;
}