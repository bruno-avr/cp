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

bool check(vector<ll> &v, ll size, ll k) {
    for (auto &el : v) {
        if (el < 1) {
            k -= 1;
            el = 1;
        }
    }
    if (size == 1) return k >= 0;
    size -= 1;

    int numEach = size / v.size() + 1;
    int numMore = (size) % v.size();
    for (int i = 0; i < v.size(); i++) {
        if (i < numMore) {
            if (v[i] < numEach+1) {
                k -= numEach+1-v[i];
            }
        } else {
            if (v[i] < numEach) {
                k -= (numEach-v[i]);
            }
        }
    }
    return k >= 0;
}

ll binarySearch(vector<ll> &v, ll l, ll r, ll k) {
    ll res = -1;
    while (l <= r) {
        ll m = l + (r - l) / 2;
 
        if (check(v, m, k)) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
 
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    };
    sort(all(v), [](const ll &a, const ll &b) {
        return b < a;
    });
    ll max = 1e18;
    // cout << check(v, 14, k) << endl;
    cout << binarySearch(v, 1, 100, k) << endl;
    
    
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}