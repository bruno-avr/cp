#include "bits/stdc++.h"
using namespace std;

#define ll long long

ll memo[100010][20];
int memoPossible[100010][27][20];

vector<char> chars;
ll n, maxLevel, p;
string s;
vector<ll> money(260);

ll pwr(ll a, ll b) {
    ll prod = 1;
    for (; b; b >>= 1) {
        if (b&1) prod = prod*a;
        a *= a;
    }
    return prod;
}

bool isPossible(ll i, char c, ll level) {
    if (i >= n) return true;

    int &res = memoPossible[i][c-'A'][level];
    if (res != -1) return res;

    res = true;

    if (s[i] != '?' && s[i] != c) {
        res = false;
    } else {
        ll skip = pwr(p, level);
        res &= isPossible(i+skip, c, level);
    }
    return res;
}

ll dp(ll i, ll level) {
    if (level > maxLevel) return 0;
    if (i >= n) return 0;

    ll &res = memo[i][level];
    if (res != -1) return res;

    res = 0;
    for (auto &c : chars) {
        if (isPossible(i, c, level)) {
            ll levelMoney = (n / pwr(p, level)) * money[c];
            res = max(res, (maxLevel - level + 1) * levelMoney);
        }
    }
    res = max(res,
        dp(i, level+1) +
        dp(i+pwr(p, level), level+1)
    );
    return res;
}

int main() {
    for(int i = 0; i < 100000; i++) {
        cout << "?";
    }

    return 0;
}