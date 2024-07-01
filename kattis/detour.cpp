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
const ll MAX = 100010;
ll d[MAX];
vector<pair<ll, ll>> g[MAX]; // {vizinho, peso}

ll n, m;
 
void dijkstra(ll v) {
	for (ll i = 0; i < n; i++) d[i] = INFLL;
	d[v] = 0;
	priority_queue<pair<ll, ll>> pq;
	pq.emplace(0, v);
 
	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > d[u]) continue;
 
		for (auto [idx, w] : g[u]) if (d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.emplace(-d[idx], idx);
		}
	}
}

bool visited[MAX];
set<pair<ll,ll>> prohibited;

vector<ll> res;
void dfs2(ll u) {
    visited[u] = 1;
    res.push_back(u);
    if (res.back() == 1) {
        cout << res.size() << " ";
        f(i,0,res.size()) {
            if (i > 0) cout << " ";
            cout << res[i];
        }
        cout << endl;
        exit(0);
    }
    for (auto [viz, w] : g[u]) {
        if (prohibited.count({u, viz}) == 0) if (!visited[viz]) dfs2(viz);
    }
    res.pop_back();
}

void solve() {
    memset(visited, 0, sizeof visited);
    ll a, b, w;
    cin >> n >> m;
    f(i,0,m) {
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    dijkstra(1);
    f(i,0,n) {
        ll minValue = INFLL, minVertex = -1;
        for (auto [viz, we] : g[i]) {
            ll thisD = we + d[viz];
            if (thisD < minValue) {
                minValue = thisD;
                minVertex = viz;
            }
        }
        prohibited.insert({i, minVertex});
    }
    dfs2(0);
    cout << "impossible" << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}