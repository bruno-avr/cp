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

unordered_map<string,bool> visited;
unordered_map<string, unordered_set<string>> graph;

bool dfs(string &u) {
    visited[u] = true;
    bool res = false;
    for (auto viz : graph[u]) {
        if (visited[viz]) return true;
        res = res or dfs(viz);
    }
    visited[u] = false;
    return res;
}

void solve() {
    int n;
    cin >> n;
    string a, b;
    f(i,0,n) {
        cin >> a >> b;
        graph[a].insert(b);
    }
    string c;
    while (cin >> c) {
        bool res = dfs(c);
        cout << c << " " << (res ? "safe" : "trapped") << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}