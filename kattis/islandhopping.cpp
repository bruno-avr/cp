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

vector<tuple<ld, int, int>> edg; // {peso,[x,y]}

// DSU em O(a(n))
vector<int> p;
void dsu_build(int n) {
    p.assign(n, 0); iota(all(p), 0);
}
int find(int i) {
    return (p[i] == i) ? i : (p[i] = find(p[i]));
}
void unite(int a, int b) {
    p[find(a)] = find(b);
}

pair<ld, vector<tuple<ld, int, int>>> kruskal(int n) {
	dsu_build(n);
	sort(edg.begin(), edg.end());
	
	ld cost = 0;
	vector<tuple<ld, int, int>> mst;
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
    int m; cin >> m;
    ld a, b;
    vector<pair<ld,ld>> points(m);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        points[i] = {a, b};
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i != j) {
                edg.push_back({sqrtl(powl(abs(points[i].first - points[j].first), 2) + powl(abs(points[i].second - points[j].second), 2)), i, j});
            }
        }
    }
    auto res = kruskal(m);
    cout << fixed << setprecision(10) << res.first << endl;
}

int main() {
    optimize;
    int T; cin >> T;
    while (T--) solve();

    return 0;
}