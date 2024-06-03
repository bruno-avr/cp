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

vector<int> weights, values;

// each memo[i][j] represents the min weight to achieve value j
// given we analysed the first i items
int memo[1001][2001]; // items * values
int dp(int index, int totalNeeded) {
    if (totalNeeded <= 0) return 0; // take no items
    if (index == weights.size()) return INF; // item doesnt exist
    if (memo[index][totalNeeded] != -1) return memo[index][totalNeeded];
    int &res = memo[index][totalNeeded];
    return res = min(
        dp(index+1, totalNeeded), // dont take item
        dp(index+1, totalNeeded - values[index]) + weights[index] // take item
    );
}



// ll memo[102][100010];
ll n, w;

// ll knapsack(ll index, ll value) {
//     if (index == 0) return 987654;
//     if (value == -1) return 0;
//     ll &res = memo[index][value];
//     if (res != -1) return res;
//     res = min(res, memo[index+1][value]);
//     ll &res2 = memo[index+1][value-values[index]];
//     if (res2 != -1) res2 = weights[index];
//     else {
//         res2 = min(res2, res+weights[index]);
//     }
//     return min(res, res2);
// }

void solve() {
    // memset(memo, -1, sizeof(memo));
    cin >> n >> w;
    weights.assign(n, 0);
    values.assign(n, 0);
    f(i,0,n) {
        cin >> weights[i] >> values[i];
    }
    // ll res = knapsack(0, 0);
    // cout << res << endl;

    vector<vector<ll>> dp(101, vector<ll>(100001, -1));
    // ll dp[101][100001];
    // memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 0; j < 100001; j++) {
            if (dp[i-1][j] != -1) {
                if (dp[i][j] == -1) dp[i][j] = dp[i-1][j];
                else dp[i][j] = min(dp[i][j], dp[i-1][j]);

                if (dp[i][j+values[i-1]] == -1) dp[i][j+values[i-1]] = dp[i-1][j] + weights[i-1];
                else dp[i][j+values[i-1]] = min(dp[i][j+values[i-1]], dp[i-1][j] + weights[i-1]);
            }
        }
    }
    for (ll i = 100000; i >= 0; i--) {
        if (dp[n][i] != -1 && dp[n][i] <= w) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}