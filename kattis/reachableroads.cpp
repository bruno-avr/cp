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


vector<bool> visited;
vector<vector<int>> graph;
int res;

void dfs(int u) {
    visited[u] = true;
    for (auto viz : graph[u]) {
        if (!visited[viz]) dfs(viz);
    }
}

void solve() {
    int n, m, x, y;
    cin >> n >> m;
    graph.assign(n, vector<int>());
    visited.assign(n, false);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    res = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            res++;
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