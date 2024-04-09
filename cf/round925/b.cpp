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
    ll total = 0;
    f(i, 0, n) {
        cin >> v[i];
        total += v[i];
    }
    total /= n;

    for (int i = n-2; i >= 0; i--) {
        if (v[i+1] < total) {
            v[i] -= total - v[i+1];
        }
    }

    if (v[0] < total) no();
    else yes();
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}