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
    ll n, m, a;
    cin >> n >> m;
    vector<ll> canSizes(n);
    for (ll i = 0; i < n; i++) {
        cin >> canSizes[i];
    }
    sort(all(canSizes));

    ll totalWasted = 0;
    for (ll i = 0; i < m; i++) {
        cin >> a;
        auto it = lower_bound(all(canSizes), a);
        totalWasted += *it - a;
    }
    cout << totalWasted << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}