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

ll calc(vector<pair<ll, ll>> &v, ll k) {
    sort(all(v));
    ll res = 0;
    for (ll i = 0; i < v.size(); i++) {
        ll curr = v[i].second;
        while (curr > 0) {
            curr -= k;
            res -= 2*v[i].first;
        }
        if (curr < 0) {
            curr *= -1;
            for (ll j = i+1; j < v.size(); j++) {
                int diff = min(v[j].second, curr);
                v[j].second -= diff;
                curr -= diff;
                if (!curr) break;
            }
        }
    }
    return res;
}

void solve() {
    // f(i,501,1501) cout << i << " 800" << endl;
    // return;
    ll n, k, a, b;
    cin >> n >> k;
    vector<pair<ll, ll>> pos, neg;
    for (ll i = 0; i < n; i++) {
        cin >> a >> b;
        if (a < 0) neg.push_back({a, b});
        else pos.push_back({-a, b});
    }
    ll res = calc(pos, k) + calc(neg, k);
    cout << res << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}