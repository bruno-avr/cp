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

ll n;
vector<ll> v;
// ll memo[101][20010];
// ll dp(ll id, ll price) {
//     if (price == 0) return 0;
//     if (id == n) return INF;

//     ll &res = memo[id][price];
//     if (res != -1) return res;

//     return res = min(
//         dp(id+1, price),
//         dp(id+1, price-v[id])+1
//     );
// }

void solve() {
    ll price; cin >> price;
    cin >> n;
    v.assign(n, 0);
    f(i,0,n) {
        cin >> v[i];
    }
    ll maxJ = 20010;
    ll dp[n+1][maxJ];
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= 10000; j++) {
            if (dp[i-1][j] != -1) {
                if (dp[i][j] == -1) dp[i][j] = dp[i-1][j];
                else dp[i][j] = min(dp[i][j], dp[i-1][j]);

                if (dp[i][j+v[i-1]] == -1) dp[i][j+v[i-1]] = dp[i-1][j]+1;
                else dp[i][j+v[i-1]] = min(dp[i][j+v[i-1]], dp[i-1][j]+1);
            }
        }
    }
    for (ll i = price; i < maxJ; i++) {
        // cout << i << " " << dp[n][i] << endl;
        if (dp[n][i] != -1) {
            cout << i << " " << dp[n][i] << endl;
            return;
        }
    }
    // memset(memo, -1, sizeof memo);
    // for (ll i = price; i <= price+10001; i++) {
    //     ll aux = dp(0, i);
    //     if (aux != INF && aux != -1) {
    //         cout << i << " " << aux << endl;
    //         return;
    //     }
    // }

    // ll dp[20010];
    // f(i,0,20010) dp[i] = INF;

    // dp[0] = 0;
    // for (ll i = 0; i < 10001; i++) {
    //     if (dp[i] != INF) {
    //         for (ll j = 0; j < n; j++) {
    //             ll next = i + v[j];
    //             dp[next] = min(dp[next], dp[i]+1);
    //         }
    //     }
    // }
    // for (ll i = price; i < 20010; i++) {
    //     if (dp[i] != INF) {
    //         cout << i << " " << dp[i] << endl;
    //         return;
    //     }
    // }
}

int main() {
    optimize;
    ll T;
    cin >> T;

    while (T--) solve();

    return 0;
}