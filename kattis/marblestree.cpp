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

int res;

int dfs(vector<vector<int>> &graph, vector<int> &marbles, int x) {
    for (auto viz : graph[x]) {
        marbles[x] += dfs(graph, marbles, viz);
    }
    res += abs(marbles[x] - 1);
    return marbles[x] - 1;
}

void solve(int n) {
    res = 0;
    int v, d;
    vector<vector<int>> graph(n);
    vector<int> marbles(n);
    vector<bool> hasParent(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v >> marbles[i] >> d;
        for (int j = 0; j < d; j++) {
            cin >> v; v--;
            hasParent[v] = true;
            graph[i].push_back(v);
        }
    }
    int root;
    for (int i = 0; i < n; i++) if (!hasParent[i]) root = i;
    dfs(graph, marbles, root);
    
    cout << res << endl;
}

int main() {
    optimize;
    int n;
    while (cin >> n, n) solve(n);

    return 0;
}