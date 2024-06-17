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
int n;
vector<int> g[MAX];
vector<int> gi[MAX]; // grafo invertido
int vis[MAX];
stack<int> S;
int comp[MAX]; // componente conexo de cada vertice
bool visited[MAX];
vector<int> aux;
unordered_map<int, int> aux2;

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);

	S.push(k);
}

void scc(int k, int c) {
	vis[k] = 1;
	comp[k] = c;
    aux2[c] = k;
	for (int i = 0; i < (int) gi[k].size(); i++)
		if (!vis[gi[k][i]]) scc(gi[k][i], c);
}
void kosaraju() {
	for (int i = 0; i < n; i++) vis[i] = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	for (int i = 0; i < n; i++) vis[i] = 0;
	while (S.size()) {
		int u = S.top();
		S.pop();
		if (!vis[u]) {
            scc(u, u);
            aux.push_back(u);
        }
	}
}

void dfs2(int u) {
    visited[u] = 1;
    int res = true;
    for (auto viz : g[u]) {
        if (visited[viz] == 0) {
            dfs2(viz);
        }
    }
}

void solve() {
    memset(visited, 0, sizeof visited);
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i++) {
        g[i].clear();
        gi[i].clear();
    }
    aux.clear();
    aux2.clear();
    int m, x, y;
    cin >> n >> m;
    f(i,0,m) {
        cin >> x >> y; x--; y--;
        g[x].push_back(y);
        gi[y].push_back(x);
    }
    kosaraju();
    int res = 0;
    for (auto el : aux) {
        // cout << aux2[el] << endl;
        if (!visited[aux2[el]]) {
            res++;
            dfs2(aux2[el]);
        }
    }
    cout << res << endl; 
}

int main() {
    optimize;
    int T; cin >> T;
    while (T--) solve();

    return 0;
}