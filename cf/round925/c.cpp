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

ll calc(vector<ll> &v, ll n) {
    ll first = v[0];
    ll start = -1, end;
    f(i, 1, n) {
        if (v[i] != first) {
            start = i;
            break;
        }
    }
    if (start == -1) return 0;

    for(int i = n-1; i >= 0; i--) {
        if (v[i] != first) {
            end = i;
            break;
        }
    }
    return end - start + 1;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    f(i, 0, n) {
        cin >> v[i];
    }

    ll res = calc(v, n);
    reverse(v.begin(),v.end());
    res = min(res, calc(v, n));
    cout << res << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}