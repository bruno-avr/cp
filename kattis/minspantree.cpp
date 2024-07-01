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
    p.resize(n);
    iota(all(p), 0);
}
int find(int a) {
    return (p[a] == a) ? a : (p[a] = find(p[a]));
}
void unite(int a, int b) {
    p[find(a)] = find(b);
}

pair<ll, vector<tuple<int, int>>> kruskal(int n) {
	dsu_build(n);
	sort(edg.begin(), edg.end());
	
	ll cost = 0;
	vector<tuple<int, int>> mst;
    int comp = n;
	for (auto [w,x,y] : edg) if (find(x) != find(y)) {
		if (x < y) mst.emplace_back(x, y);
		else mst.emplace_back(y, x);
		cost += w;
		unite(x,y);
        comp--;
	}
    sort(all(mst));
    if (comp != 1) return {-1, mst};
	return {cost, mst};
}

int n, m;

void solve() {
    int a, b, c;
    edg.clear();
    p.clear();
    f(i,0,m) {
        cin >> a >> b >> c;
        edg.emplace_back(c, a, b);
    }
    auto res = kruskal(n);
    if (res.first == -1) {
        cout << "Impossible" << endl;
        return;
    }
    cout << res.first << endl;
    for (auto [u, v] : res.second) {
        cout << u << " " << v << endl;
    }
}

int main() {
    optimize;
    while (cin >> n >> m, n) solve();

    return 0;
}