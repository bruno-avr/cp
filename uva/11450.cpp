#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
#define ld long double
#define pii pair<ll,ll>

#define fi first
#define se second
#define pb push_back

#define all(x) x.begin(),x.end()

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 998244353LL

#define f(i,s,e) for(ll i=s;i<e;i++)
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int memo[30][210];

int dp(int c, int money, vector<vector<int>> &garments) {
    if (money < 0) return INT_MAX;
    if (c == garments.size()) return money;

    if (memo[c][money] != -1) return memo[c][money];

    int &res = memo[c][money];
    res = INT_MAX;
    for (auto &el : garments[c]) {
        res = min(res, dp(c+1, money-el, garments));
    }
    return res;
}

void solveTopDown() {
    memset(memo, -1, sizeof(memo));
    int m, c, k;
    cin >> m >> c;
    vector<vector<int>> garments(c);
    f(i,0,c) {
        cin >> k;
        garments[i].assign(k, 0);
        f(j,0,k) cin >> garments[i][j];
    }
    int res = dp(0,m,garments);
    if (res == INT_MAX) cout << "no solution" << endl;
    else cout << m-res << endl;
}

void solveBottomUp() {
    int m, c, k;
    cin >> m >> c;
    vector<vector<int>> garments(c);
    f(i,0,c) {
        cin >> k;
        garments[i].assign(k, 0);
        f(j,0,k) cin >> garments[i][j];
    }
    bool dp[c+1][m+1];
    memset(dp, false, sizeof(dp));
    dp[0][m] = true;
    for (int i = 1; i < c+1; i++) {
        for (int j = 0; j < m+1; j++) {
            if (dp[i-1][j]) {
                for (auto &el : garments[i-1]) {
                    if (j-el >= 0) dp[i][j-el] = true;
                }
            }
        }
    }

    for (int i = 0; i < m+1; i++) {
        if (dp[c][i]) {
            cout << m-i << endl;
            return;
        }
    }

    cout << "no solution" << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solveTopDown();

    return 0;
}