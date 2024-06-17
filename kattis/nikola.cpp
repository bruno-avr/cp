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

const int MAXN = 1010;
int n;
int v[MAXN];
// int memo[MAXN][MAXN];

// void dp(int i, int jump, int val) {
//     if (i >= n or i < 0) return;
//     if (jump >= n) return;
//     val += v[i];

//     int &res = memo[i][jump];
//     if (res != -1 && val >= res) return;
//     res = val;
//     if (jump) dp(i-jump, jump, res);
//     dp(i+jump+1, jump+1, res);
// }

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    int dp[n+1][n+1];
    f(i,0,n+1)
    f(j,0,n+1) dp[i][j] = INF;
    // memset(dp, -1, sizeof dp);
    // memset(memo, -1, sizeof memo);
    dp[0][0] = 0;
    for (int jump = 0; jump < n; jump++) {
        for (int pos = n-1; pos >= 0; pos--) {
            if (dp[jump][pos] != INF) {
                // cout << jump << " " << pos << endl;
                if (pos-jump >= 0) dp[jump][pos-jump] = min(dp[jump][pos-jump], dp[jump][pos]+v[pos-jump]);
                if (pos+jump+1 < n) dp[jump+1][pos+jump+1] = min(dp[jump+1][pos+jump+1], dp[jump][pos]+v[pos+jump+1]);
            }
        }
    }
    // dp(0, 0, 0);
    int res = INF;
    for (int i = 0; i < n; i++) {
        if (dp[i][n-1] != -1) {
            // cout << i << endl;
            // cout << memo[n-1][i] << endl;
            res = min(res, dp[i][n-1]);
        }
    }
    cout << res << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}