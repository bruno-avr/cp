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

void dfs(vector<vector<pair<int, int>>> &v, int day, int x) {
    visited[x] = true;
    for (auto &el : v[x]) {
        if (!visited[el.first] && day >= el.second) {
            dfs(v, day, el.first);
        }
    }
}

bool p(int x, vector<vector<pair<int, int>>> &v, int k) {
    visited.assign(v.size(), false);
    dfs(v, x, 0);
    int cont = 0;
    f(i,0,v.size()) {
        if (visited[i]) cont++;
    }
    // cout << cont << " " << k << endl;
    return cont >= k;
}

int bs(int l, int r, vector<vector<pair<int, int>>> &v, int k) {
    while(l<r) {
        int m = l + (r-l)/2;

        p(m, v, k) ? r = m : l = m+1;
    }
    return p(l, v, k) ? l : -1;
}

void solve() {
    int n, m, k, u, v, c;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> vec(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        u--; v--;
        vec[u].push_back({v, c});
        vec[v].push_back({u, c});
    }
    int res = bs(0, 10000, vec, k);
    cout << res << endl;
    // cout << p(3, vec, k) << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}