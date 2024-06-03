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

const int MAX_COST = 30010;
// int memo[101][MAX_COST];

int n;

// int knapsack(int index, int money) {
//     if (index == n) return 0;
//     int &ans = memo[index][money];
//     if (ans != -1) return memo[index][money];
//     ans = knapsack(index+1, money);
//     if (money-weight[index] >= 0) {
//         return ans = max(
//             knapsack(index+1, money),
//             knapsack(index+1, money-weight[index]) + value[index]
//         );
//     }
//     return ans = knapsack(index+1, money);
// }

void solve() {
    cin >> n;
    // for (int i = 0; i < 30010; i++) memo[0][i] = 0;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    int dp[MAX_COST];
    vector<vector<int>> setdp(MAX_COST, vector<int>(n,0));
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < MAX_COST; i++) {
        if (dp[i] > 0) {
            for (int j = 0; j < n; j++) {
                if (i+cost[j] < MAX_COST) {
                    if (dp[i+cost[j]] == -1) continue;
                    setdp[i][j]++;
                    if (dp[i+cost[j]] == 1) {
                        if (setdp[i] != setdp[i+cost[j]]) dp[i+cost[j]] = -1;
                    } else {
                        dp[i+cost[j]] = 1;
                        f(k,0,n) setdp[i+cost[j]][k] = setdp[i][k];
                    }
                    setdp[i][j]--;
                }
            }
        } else if (dp[i] < 0) {
            for (int j = 0; j < n; j++) {
                if (i+cost[j] < MAX_COST) {
                    dp[i+cost[j]] = -1;
                }
            }
        }
    }

    // int dp[n][MAX_COST];
    // memset(dp, 0, sizeof(dp));

    // for (int i = 0; i < MAX_COST; i+=cost[0]) {
    //     dp[0][i] = 1;
    // }
    // for (int i = 1; i < n; i++) {
    //     for (int j = 0; j < cost[i]; j++) {
    //         if (dp[i-1][j] != 0) {
    //             for (int k = j; k < MAX_COST; k+=cost[i]) {
    //                 dp[i][k] = max(dp[i][k], dp[i-1][j]);
    //                 if (k+cost[i] < MAX_COST) {
    //                     dp[i][k+cost[i]] = max(dp[i][k+cost[i]]+1, dp[i-1][j]);
    //                 }
    //             }
    //         }
    //     }
    // }

    int m, a;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        if (dp[a] == 0) {
            cout << "Impossible" << endl;
        } else if (dp[a] == -1) {
            cout << "Ambiguous" << endl;
        } else {
            bool first = true;
            for (int j = 0; j < n; j++) {
                for(int k = 0; k < setdp[a][j]; k++) {
                    if (first) first = false;
                    else cout << " ";
                    cout << j+1;
                }
            }
            cout << endl;
        }
    }
    // for (int i = 0; i < 30; i++) {
    //     cout << dp[i] << " ";
    // }
}

int main() {
    optimize;
    solve();

    return 0;
}