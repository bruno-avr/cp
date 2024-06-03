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

int c, n;
const int MAXN = 2010;
int memo[MAXN][MAXN];
vector<int> value(MAXN), weight(MAXN);

int knapsack(int index, int money) {
    if (index == n) return 0;
    int &ans = memo[index][money];
    if (ans != -1) return memo[index][money];
    ans = knapsack(index+1, money);
    if (money-weight[index] >= 0) {
        return ans = max(
            knapsack(index+1, money),
            knapsack(index+1, money-weight[index]) + value[index]
        );
    }
    return ans = knapsack(index+1, money);
}

vector<int> res;
void getRes(int index, int money) {
    if (index == n) return;
    int &ans = memo[index][money];
    if (ans == knapsack(index+1, money)) {
        getRes(index+1, money);
    } else {
        res.push_back(index);
        getRes(index+1, money-weight[index]);
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
    }
    memset(memo, -1, sizeof(memo));
    res.clear();
    knapsack(0, c);
    getRes(0, c);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << endl;

    // int dp[n+1][c+1];
    // memset(dp, -1, sizeof(dp));
    // dp[0][c] = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= c; j++) {
    //         if (dp[i-1][j] != -1) {
    //             if (j >= weight[i-1]) {
    //                 dp[i][j-weight[i-1]] = max(dp[i][j-weight[i-1]], dp[i-1][j]+value[i-1]);
    //             }
    //             dp[i][j] = max(dp[i][j], dp[i-1][j]);
    //         }
    //     }
    // }
    // int res = 0;
    // for (int j = 0; j <= c; j++) {
    //     res = max(res, dp[n][j]);
    // }
    // cout << res << endl;
}

int main() {
    optimize;
    while (cin >> c >> n) solve();

    return 0;
}