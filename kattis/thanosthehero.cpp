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
    reverse(all(v));
    ll k = 0;
    for (ll i = 1; i < n; i++) {
        if (v[i] >= v[i-1]) {
            ll diff = v[i] - v[i-1] + 1;
            k += diff;
            v[i] -= diff;
            if (v[i] < 0) {
                cout << 1 << endl;
                return;
            }
        }
    }
    cout << k << endl;
    
    
}

int main() {
    optimize;
    solve();

    return 0;
}