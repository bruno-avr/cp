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

const int MAX = 100010;
int n, s1, t;
ll d[MAX];
vector<pair<int, int>> g[MAX]; // {vizinho, peso}
vector<pair<int, int>> gR[MAX]; // {vizinho, peso}
vector<unordered_set<int>> g2; // {vizinho, peso}

stack<int> s;
vector<int> id, art;

int dfs_art(int i, int& t, int p = -1) {
	int lo = id[i] = t++;
	s.push(i);
	for (int j : g2[i]) if (j != p) {
		if (id[j] == -1) {
			int val = dfs_art(j, t, i);
			lo = min(lo, val);

			if (val >= id[i]) {
				art[i]++;
				while (s.top() != j) s.pop();
				s.pop();
			}
			// if (val > id[i]) aresta i-j eh ponte
		}
		else lo = min(lo, id[j]);
	}
	if (p == -1 and art[i]) art[i]--;
	return lo;
}

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

ll dR[MAX];
void dijkstraR(int v) {
	for (int i = 0; i < n; i++) dR[i] = INFLL;
	dR[v] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.emplace(0, v);
 
	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > dR[u]) continue;
 
		for (auto [idx, w] : gR[u]) if (dR[idx] > dR[u] + w) {
			dR[idx] = dR[u] + w;
			pq.emplace(-dR[idx], idx);
		}
	}
}

void compute_art_points() {
    id = vector<int>(n, -1);
    art = vector<int>(n, 0);
    int t = 0;
    dfs_art(s1, t, -1);
}

void solve() {
    int m, a, b, c;
    cin >> n >> m;
    g2.assign(n, unordered_set<int>());
    f(i,0,m) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        gR[b].push_back({a, c});
    }
    cin >> s1 >> t;
    dijkstra(s1);
    dijkstraR(t);

    bool visited[100010];
    queue<int> q;
    q.push(s1);
    visited[s1] = true;
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for (auto [viz, w] : g[curr]) {
            if (d[viz] + dR[viz] == d[t]) { // viz faz parte do caminho minimo
                g2[curr].insert(viz);
                g2[viz].insert(curr);
                if (!visited[viz]) {
                    visited[viz] = true;
                    q.push(viz);
                }
            }
        }
    }
    compute_art_points();

    set<int> res;
    for (int i = 0; i < n; i++) {
        if (art[i] >= 1 && i != s1 && i != t) res.insert(i);
    }

    res.insert(s1);
    res.insert(t);
    bool first = true;
    for (auto el : res) {
        if (first) first = 0;
        else cout << " ";
        cout << el;
    }
    cout << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}