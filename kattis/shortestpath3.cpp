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

int d[MAX];
bool invalid[MAX];
bool visited[MAX];
vector<pair<int, int>> ar; // vetor de arestas
vector<int> w;              // peso das arestas

void bellman_ford(int a) {
	for (int i = 0; i < n; i++) d[i] = INF;
	d[a] = 0;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < m; j++) {
            if (d[ar[j].first] == INF) continue;
			if (d[ar[j].second] > d[ar[j].first] + w[j]) {
				if (i >= n) invalid[ar[j].second] = 1;
                d[ar[j].second] = d[ar[j].first] + w[j];
			}
		}

}

vector<vector<int>> g;
void dfs(int x) {
    visited[x] = 1;
    for(auto viz : g[x]) if(!visited[viz]) dfs(viz);
}
void dfs2(int x) {
    visited[x] = 1;
    invalid[x] = 1;
    for(auto viz : g[x]) if(!visited[viz]) dfs2(viz);
}

void solve(int c) {
    g.clear();
    g.assign(n, vector<int>());
    ar.clear();
    w.clear();
    memset(invalid, 0, sizeof invalid);
    memset(visited, 0, sizeof visited);
    if (c) cout << endl;
    int a, b, w1;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w1;
        ar.push_back({a,b});
        w.push_back(w1);
        g[a].push_back(b);
    }
    bellman_ford(s);
    for (int i = 0; i < n; i++) if (invalid[i] and !visited[i]) dfs2(i);
    memset(visited, 0, sizeof visited);
    // dfs(s);
    for (int i = 0; i < q; i++) {
        cin >> a;
        if (invalid[a]) cout << "-Infinity" << endl;
        else if (d[a] == INF) cout << "Impossible" << endl;
        else cout << d[a] << endl;
    }
}

int main() {
    optimize;
    int c = 0;
    while(cin>>n>>m>>q>>s, n) solve(c++);

    return 0;
}