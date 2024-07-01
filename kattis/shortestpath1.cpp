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

int n, m, q, s;
const int MAX = 10010;
ll d[MAX];
vector<pair<int, int>> g[MAX]; // {vizinho, peso}
 
void dijkstra(int v) {
	for (int i = 0; i < n; i++) d[i] = INFLL;
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

void solve(int c) {
    if (c) cout << endl;
    f(i,0,n) g[i].clear();
    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        g[a].push_back({b,w});
    }
    dijkstra(s);
    for (int i = 0; i < q; i++) {
        cin >> a;
        if (d[a] == INFLL) cout << "Impossible" << endl;
        else cout << d[a] << endl;
    }
}

int main() {
    optimize;
    int c = 0;
    while(cin>>n>>m>>q>>s, n) solve(c++);

    return 0;
}