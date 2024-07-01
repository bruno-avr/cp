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

vector<tuple<ll, ll, ll>> edg; // {peso,[x,y]}

// DSU em O(a(n))
vector<ll> p;
void dsu_build(ll n) {
    p.resize(n);
    iota(all(p), 0);
}
ll find(ll a) {
    return (p[a] == a) ? a : (p[a] = find(p[a]));
}
void unite(ll a, ll b) {
    p[find(a)] = find(b);
}

ll kruskal(ll n) {
	sort(edg.begin(), edg.end());
	
	ll cost = 0;
	for (auto [w,x,y] : edg) if (find(x) != find(y)) {
		cost += w;
		unite(x,y);
	}
	return cost;
}

void solve() {
    edg.clear();
    p.clear();
    ll n, m, l, s;
    cin >> n >> m >> l >> s;
	dsu_build(n);
    ll a, b, w;
    cin >> a; a--;
    ll res = n-1;
    f(i,1,s) {
        cin >> b; b--;
        if (find(a) != find(b)) unite(a, b);
        res--;
    }
    res *= l;
    f(i,0,m) {
        cin >> a >> b >> w; a--; b--;
        edg.emplace_back(w, a, b);
    }
    res += kruskal(n);
    cout << res << endl;
}

int main() {
    optimize;
    ll T; cin >> T;
    while (T--) solve();

    return 0;
}