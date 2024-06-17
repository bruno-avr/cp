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

vector<int> g[5010];
vector<int> gi[5010];
bool visited[5010];

int dfs1(int u) {
    visited[u] = true;
    int cont = 1;
    for (auto v : gi[u]) {
        if (!visited[v]) cont += dfs1(v);
    }
    return cont;
}

int dfs2(int u) {
    visited[u] = true;
    int cont = 1;
    for (auto v : g[u]) {
        if (!visited[v]) cont += dfs2(v);
    }
    return cont;
}

int a, b, e, p, x, y;

int compute(int k) {
    int res = 0;
    for (int i = 0; i < e; i++) {
        memset(visited, false, sizeof visited);
        int cont = dfs2(i);

        if (e - cont < k) res++;
    }
    return res;
}

void solve() {
    cin >> a >> b >> e >> p;
    f(i,0,p) {
        cin >> x >> y;
        g[x].push_back(y);
        gi[y].push_back(x);
    }

    int first = compute(a);
    int second = compute(b);

    int third = e;
    for (int i = 0; i < e; i++) {
        memset(visited, false, sizeof visited);
        if (dfs1(i) <= b) third--;
    }
    
    cout << first << endl;
    cout << second << endl;
    cout << third << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}