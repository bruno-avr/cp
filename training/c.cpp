#include "bits/stdc++.h"
using namespace std;

#define ll long long

ll memo[100010][20];
int memoPossible[100010][27][20];
ll memoSum[100010][20];

vector<char> chars;
ll n, maxLevel, p;
string s;
vector<ll> money(260);

int pwr(int a, int b) {
    int prod = 1;
    for (; b; b >>= 1) {
        if (b&1) prod = prod*a;
        a *= a;
    }
    return prod;
}

bool isPossible(int i, char c, int level) {
    if (i >= n) return true;

    int &res = memoPossible[i][c-'A'][level];
    if (res != -1) return res;

    res = 1;

    if (s[i] != '?' && s[i] != c) {
        res = 0;
    } else {
        int skip = pwr(p, level);
        res &= isPossible(i+skip, c, level);
    }
    return res;
}

ll dp(int i, int level) {
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
    if (memoSum[i][level] == -1) {
        ll thisV = 0;
        int step = pwr(p, level);
        int cmp = pwr(p, level+1);
        for (int j = i; (j < cmp) && (j < 100010); j+=step) {
            if (memoSum[j][level] != -1) {
                thisV += memoSum[j][level];
                break;
            }
            thisV += dp(j, level+1);
        }
        for (int j = i; (j < cmp) && (j < 100010); j+=step) {
            if (memoSum[j][level] != -1) break;
            memoSum[j][level] = thisV;
            thisV -= dp(j, level+1);
        }
    }
    res = max(res, memoSum[i][level]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(memo, -1, sizeof memo);
    memset(memoPossible, -1, sizeof memoPossible);
    memset(memoSum, -1, sizeof memoSum);
    cin >> n; // 1e5
    cin >> s;
    p = -1;
    for (ll i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            p = i;
            break;
        }
    }
    if(p == -1) p = n;
    maxLevel = 0;
    for (ll i = 1; i < n; i*=p) maxLevel++;

    int k;
    string c;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> c;
        chars.push_back(c[0]);
        cin >> money[c[0]];
    }

    ll res = dp(0, 0);
    cout << res << endl;

    return 0;
}