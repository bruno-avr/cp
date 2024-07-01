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

vector<tuple<int, int, int>> edg; // {peso,[x,y]}

// DSU em O(a(n))
vector<int> p;
void dsu_build(int n) {
    p.assign(n, 0);
    iota(all(p), 0);
}
int find(int a) {
    return (p[a] == a) ? a : p[a] = find(p[a]);
}
void unite(int a, int b) {
    p[find(a)] = find(b);
}

pair<ll, vector<tuple<int, int, int>>> kruskal(int n) {
	dsu_build(n);
	sort(edg.begin(), edg.end());
	
	ll cost = 0;
	vector<tuple<int, int, int>> mst;
	for (auto [w,x,y] : edg) if (find(x) != find(y)) {
		mst.emplace_back(w, x, y);
		cost += w;
		unite(x,y);
	}
	return {cost, mst};
}

void solve() {
    edg.clear();
    p.clear();
    int m, cats, a, b, c;
    cin >> m >> cats;
    for(int i = 0; i < (cats*(cats-1))/2; i++) {
        cin >> a >> b >> c;
        edg.emplace_back(c, a, b);
    }
    auto [res, _] = kruskal(cats);
    cout << ((m >= res + cats) ? "yes" : "no") << endl;
}

int main() {
    optimize;
    int T; cin >> T;
    while (T--) solve();

    return 0;
}