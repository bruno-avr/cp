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

#define f(i,s,e) for(ll i=s;i<e;i++)
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

const int mod = 998244353;
const int MAX_N = 300010;

ll pow_mod(ll x, ll p) {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        ll y = pow_mod(x, p / 2);
        return (y * y) % mod;
    }
    return (x * pow_mod(x, p - 1)) % mod;
}

void solve() {
    ll n, a, b;
    cin >> n;
    vector<vector<ll>> graph(MAX_N, vector<ll>());
    for (ll i = 0; i < (n-1); i++) {
        cin >> a >> b; a--; b--;
        graph[(int)a].push_back(b);
        graph[(int)b].push_back(a);
    }

    ll numFolhas = 0;
    for (ll i = 0; i < n; i++) {
        if (graph[(int)i].size() == 1) numFolhas++;
    }

    ll res = ((n*(n-1))/2)%mod;
    res = (res + n + 1)%mod;

    ll res2 = pow_mod(2, numFolhas);
    ll res3 = ((numFolhas*(numFolhas-1))/2)%mod;

    res2 = (res2 - res3)%mod;
    res2 = (res2 - numFolhas - 1)%mod;

    res = (res + res2) % mod;
    cout << res << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}