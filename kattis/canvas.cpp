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
    ll n, a;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }
    while (pq.size() > 1) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        res += a + b;
        pq.push(a+b);
    }
    cout << res << endl;
}

int main() {
    optimize;
    ll T;
    cin >> T;

    while (T--) solve();

    return 0;
}