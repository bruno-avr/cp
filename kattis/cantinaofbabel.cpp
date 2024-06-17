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
unordered_map<int, unordered_set<int>> comps;

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);

	S.push(k);
}

void scc(int k, int c) {
	vis[k] = 1;
	comp[k] = c;
    comps[c].insert(k);
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
		if (!vis[u]) scc(u, u);
	}
}

void solve() {
    int k;
    cin >> k;
    cin.ignore();
    string line, s1, s2, s3;
    unordered_map<string, int> id;
    int idx = 0;
    unordered_set<int> users;
    f(i,0,k) {
        getline(cin, line);
        stringstream ss;
        ss << line;
        ss >> s1 >> s2;
        if (id.count(s1) == 0) id[s1] = idx++;
        if (id.count(s2) == 0) id[s2] = idx++;
        users.insert(id[s1]);
        g[id[s1]].push_back(id[s2]);
        g[id[s2]].push_back(id[s1]);
        gi[id[s1]].push_back(id[s2]);
        gi[id[s2]].push_back(id[s1]);
        while (ss >> s3) {
            if (id.count(s3) == 0) id[s3] = idx++;

            g[id[s3]].push_back(id[s1]);
            gi[id[s1]].push_back(id[s3]);
        }
    }
    n = idx;
    kosaraju();
    int maxN = 0;
    // cout << comps.size() << endl;
    for (auto &[i, cmp] : comps) {
        int curr = 0;
        for (auto &el : cmp) {
            if (users.count(el)) curr++;
        }
        // cout << curr << endl;
        maxN = max(maxN, curr);
    }
    cout << k-maxN << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}