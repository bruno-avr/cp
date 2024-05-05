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

ll total = 0;

void func(vector<ll> &v, ll currWeight, ll pos) {
    if (currWeight >= 200) {
        ll remaining = v.size() - pos;
        total += currWeight * (1l << remaining);
        f(i,pos,v.size()) total += v[i] * (1l << (remaining-1));
        return;
    }
    if (pos == v.size()) {
        return;
    }
    for (int i = pos; i < v.size(); i++) {
        func(v, currWeight+v[i], i+1);
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    func(v,0,0);
    cout << total << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}