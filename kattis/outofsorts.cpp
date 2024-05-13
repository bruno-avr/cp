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

ll binarySearch(vector<ll> &v, ll l, ll r, ll k) {
    while (l < r) {
        ll m = (l+r)/2;
        if (v[m] == k) return m;
        if (v[m] > k) r = m-1;
        else l = m+1;
    }
    if ((v[l] == k)) return l;
    return -1;
}

void solve() {
    ll n, m, a, c, x;
    cin >> n >> m >> a >> c >> x;
    vector<ll> v(n+1);
    v[0] = x;
    set<ll> values;
    f(i,1,n+1) {
        v[i] = (a*v[i-1]+c) % m;
        values.insert(v[i]);
    }
    v.assign(v.begin()+1, v.end());
    ll cont = 0;
    for (auto el : values) {
        if (binarySearch(v,0,v.size()-1, el) != -1) cont++;
    }
    cout << cont << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}