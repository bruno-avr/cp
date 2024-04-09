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

const ll MAXN = 200010;
bool error;
vector<vector<int>> graph(MAXN);
vector<int> visited(MAXN);
vector<bool> recursionStack(MAXN, false);

void init(int numV) {
    error = false;
    for (int i = 0; i < numV; i++) {
        graph[i].clear();
        visited[i] = false;
    }
}

void dfs(int v) {
    visited[v] = true;
    recursionStack[v] = true;

    for (int u : graph[v]) {
        if (!visited[u]) dfs(u);
        if (recursionStack[u]) {
            error = true;
        }
    }
    recursionStack[v] = false;
}

void solve() {
    int n, k, a, b;
    cin >> n >> k;
    init(n);

    f(i, 0, k) {
        cin >> a;
        if (n > 1) {
            cin >> a; a--;
            f(j, 2, n) {
                cin >> b; b--;
                graph[a].push_back(b);
                a = b;
            }
        }
    }

    for (int i = 0; i < n; i++) if(!visited[i]) dfs(i);

    if (error) no();
    else yes();
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}