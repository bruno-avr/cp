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

int dfs(vector<vector<int>> &graph, vector<bool> &visited, int curr, int size, int &cont) {
    visited[curr] = true;
    int value = 1;
    for (auto viz : graph[curr]) {
        if (!visited[viz]) {
            value += dfs(graph, visited, viz, size, cont);
        }
    }
    if (value >= size) {
        cont++;
        return 0;
    }
    return value;
}

bool isPossible(vector<vector<int>> &graph, int size, int numCuts) {
    vector<bool> visited(graph.size());
    int cont = 0;
    dfs(graph, visited, 0, size, cont);
    if (cont >= numCuts+1) return true;
    return false;
}

int binarySearch(vector<vector<int>> &graph, int l, int r, int numCuts) {
    int res = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        if (isPossible(graph, m, numCuts)) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
 
    return res;
}

void solve() {
    int n, k, a, b;
    cin >> n >> k;
    vector<vector<int>> graph(n);
    f(i,0,n-1) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << binarySearch(graph, 1, n, k) << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}