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

const ll MAX_H = 100010;

void solve() {
    ll m, x;
    cin >> m >> x;
    vector<ll> c(m);
    vector<ll> h(m);
    ll totalH = 1;
    f(i,0,m) {
        cin >> c[i] >> h[i];
        totalH += h[i];
    }
    ll dp[m][totalH];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = x;
    if (c[0] == 0) dp[0][h[0]] = x;
    for (ll i = 1; i < m; i++) {
        for (ll j = 0; j < totalH; j++) {
            if (dp[i-1][j] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j] + x);
                if (dp[i-1][j] >= c[i]) {
                    dp[i][j+h[i]] = max(dp[i][j+h[i]], dp[i-1][j] + x - c[i]);
                }
            }
        }
    }
    for (ll i = totalH-1; i >= 0; i--) {
        if (dp[m-1][i] != -1) {
            cout << i << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}