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

vector<vector<int>> graph;
vector<bool> visited;
vector<int> nums;

bool dfs(int u, int num) {
    visited[u] = true;
    nums[u] = num;
    bool res = false;
    for (auto viz : graph[u]) {
        if (!visited[viz]) res |= dfs(viz, 1-num);
        else {
            if (nums[viz] == num) res = true;
        }
    }
    return res;
}

void solve() {
    int n, m, u, v;
    cin >> n >> m;
    graph.assign(n, vector<int>());
    visited.assign(n, false);
    nums.assign(n, 0);
    f(i,0,m) {
        cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int res = -1;
    bool oneOdd = false;
    f(i,0,n) {
        if (!visited[i]) {
            // cout << i << endl;
            res++;
            bool found = dfs(i, 1);
            if (found) oneOdd = true;
        }
    }
    if (!oneOdd) res++;
    cout << res << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}