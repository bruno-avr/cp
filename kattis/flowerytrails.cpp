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

int n, m;
const int MAX = 10010;
ll d[MAX];
vector<pair<int, int>> g[MAX]; // {vizinho, peso}
 
void dijkstra(int v) {
	for (int i = 0; i < n; i++) d[i] = INF;
	d[v] = 0;
	priority_queue<pair<ll, int>> pq;
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
ll res = 0;
void dfs(int u, int rem) {
    visited[u] = true;
    for (auto viz : g[u]) {
        if (rem - viz.second == d[viz.first]) {
            res += viz.second;
            if (!visited[viz.first]) dfs(viz.first, rem - viz.second);
        }
    }
}

void solve() {
    memset(visited, 0, sizeof visited);
    int a, b, w;
    cin >> n >> m;
    f(i,0,m) {
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    dijkstra(n-1);
    dfs(0, d[0]);
    cout << res*2 << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}