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

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll cont = 0;
    map<vector<ll>, map<ll, ll>> mp;
    map<vector<ll>, ll> total;
    ll res = 0;
    for (ll i = 2; i < n; i++) {
        ll a = v[i-2];
        ll b = v[i-1];
        ll c = v[i];
        vector<ll> msab = {a, b, 0};
        vector<ll> msac = {a, 0, c};
        vector<ll> msbc = {0, b, c};
        res += total[msab] - mp[msab][c];
        if (msab != msac) res += total[msac] - mp[msac][b];
        if (msbc != msab && msbc != msac) res += total[msbc] - mp[msbc][a];

        mp[msab][c]++;
        total[msab]++;
        if (msab != msac) {
            mp[msac][b]++;
            total[msac]++;
        }
        if (msbc != msab && msbc != msac) {
            mp[msbc][a]++;
            total[msbc]++;
        }
    }
    
    cout << res << endl;
    
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}