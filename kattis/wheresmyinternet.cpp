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

int n, m, k, j;
vector<int> graph[200010];
bool visited[200010];

void dfs(int i) {
    visited[i] = true;
    for (auto v : graph[i]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> k >> j; k--, j--;
        graph[k].push_back(j);
        graph[j].push_back(k);
    }
    dfs(0);
    bool conn = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << i+1 << endl;
            conn = false;
        }
    }
    if (conn) {
        cout << "Connected" << endl;
    }
    
}

int main() {
    optimize;
    solve();

    return 0;
}