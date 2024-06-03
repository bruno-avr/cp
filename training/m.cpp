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


void solve() {
    int n, m, d, u, v;
    cin >> n >> m >> d;
    vector<vector<int>> graph(n);
    f(i,0,m) {
        cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int maxDist = 0;
    for (int i = 0; i < n; i++) {
        vector<bool> visited (n, false);
        queue<pair<int,int>> bfs;
        bfs.push({i, 0});
        while (!bfs.empty()) {
            auto curr = bfs.front(); bfs.pop();
            maxDist = max(maxDist, curr.second);
            visited[curr.first] = true;
            for (auto &viz : graph[curr.first]) {
                if (!visited[viz]) {
                    visited[viz] = true;
                    bfs.push({viz, curr.second+1});
                }
            }
        }
    }

    int res = (2*d+1)-maxDist;
    if (res < 0) {
        cout << 0 << " " << 0 << endl;
    } else {
        cout << res << " " << res << endl;
    }

}

int main() {
    optimize;
    solve();

    return 0;
}