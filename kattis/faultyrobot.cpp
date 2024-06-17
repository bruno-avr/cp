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

vector<int> forced;
vector<bool> visited;
vector<bool> stopped;
vector<int> g[1010];
int res = 0;

void dfs(int u, bool trunfo) {
    visited[u] = true;
    if (forced[u] == -1) {
        if (!stopped[u]) {
            stopped[u] = true;
            res++;
        }
    }
    for (auto v : g[u]) {
        if (!visited[v]) {
            if(forced[u] == v) {
                dfs(v, trunfo);
            }
        }
    }
    for (auto v : g[u]) {
        if (!visited[v]) {
            if(forced[u] != v && trunfo) {
                dfs(v, false);
            }
        }
    }
}

void solve() {
    int n, m, a, b;
    cin >> n >> m;
    forced.assign(n, -1);
    visited.assign(n, false);
    stopped.assign(n, false);

    f(i,0,m) {
        cin >> a >> b;
        bool isForced = a < 0;
        if (isForced) a = -a;
        a--; b--;
        if (isForced) {
            forced[a] = b;
        }
        g[a].push_back(b);
    }
    dfs(0, true);
    cout << res << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}