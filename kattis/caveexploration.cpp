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

int n;
vector<vector<int>> g;
stack<int> s;
vector<int> id, art;
set<pair<int,int>> bridges;

int dfs_art(int i, int& t, int p = -1) {
	int lo = id[i] = t++;
	s.push(i);
	for (int j : g[i]) if (j != p) {
		if (id[j] == -1) {
			int val = dfs_art(j, t, i);
			lo = min(lo, val);

			if (val >= id[i]) {
				art[i]++;
				while (s.top() != j) s.pop();
				s.pop();
			}
			if (val > id[i]) {
                bridges.insert({i,j});
                bridges.insert({j,i});
            }
		}
		else lo = min(lo, id[j]);
	}
	if (p == -1 and art[i]) art[i]--;
	return lo;
}

void compute_art_points() {
	id = vector<int>(n, -1);
	art = vector<int>(n, 0);
	int t = 0;
	for (int i = 0; i < n; i++) if (id[i] == -1) 
		dfs_art(i, t, -1);
}

int cont = 0;
bool visited[100010];
void dfs(int u) {
    cont++;
    visited[u] = true;
    for (auto viz : g[u]) {
        if (!visited[viz]) {
            if (bridges.count({u, viz}) == 0) {
                dfs(viz);
            }
        }
    }
}

void solve() {
    int m, a, b;
    cin >> n >> m;
    g.assign(n, vector<int>());
    f(i,0,m) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    compute_art_points();
    dfs(0);
    cout << cont << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}