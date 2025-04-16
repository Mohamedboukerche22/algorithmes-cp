#include <bits/stdc++.h>
typedef long long ll;
//typedef string str;
const int MOD = 1000000007;
using namespace std;
int main() {
    int n;
    cin >> n;
    __int128_t a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        __int128_t c = a + b;
        a = b;
        b = c;
    }
    if (n == 0) b = 0;
    string r;
    while (b > 0) {

        r += '0' + b % 10;
        b /= 10;
    }
    reverse(r.begin(), r.end());
    cout << r<< endl;
    return 0;
}
