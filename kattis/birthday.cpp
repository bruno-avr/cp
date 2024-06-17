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

int p, c, a, b;

const ll MAXN = 200010;
vector<vector<int>> graph(MAXN);
vector<bool> visited(MAXN);
vector<int> tin(MAXN);
vector<int> lowlink(MAXN);
vector<pair<int, int>> bridges;
int entryTime;

void init(int numV) {
    entryTime = 0;
    bridges.clear();
    for (int i = 0; i < numV; i++) {
        graph[i].clear();
        visited[i] = false;
    }
}

void dfs(int v, int parent) {
    visited[v] = true;
    lowlink[v] = tin[v] = entryTime++;

    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(u, v);
            lowlink[v] = min(lowlink[v], lowlink[u]);
        } else {
            if (u == parent) continue;

            lowlink[v] = min(lowlink[v], tin[u]);
        }
    }

    if (v != parent && lowlink[v] == tin[v]) {
        bridges.push_back({v, parent});
    }
}

void solve() {
    init(p);
    f(i,0,c) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < p; i++) if(!visited[i]) dfs(i,i);
    cout << (bridges.size() ? "Yes" : "No") << endl;  
}

int main() {
    optimize;
    while(cin >> p >> c, p or c) solve();

    return 0;
}