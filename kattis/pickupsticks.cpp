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
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> in(n,0);
    f(i,0,m) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    f(i,0,n) {
        if (in[i] == 0) q.push(i);
    }
    vector<int> res;
    while(!q.empty()) {
        auto el = q.front(); q.pop();
        res.push_back(el);
        for (auto viz : graph[el]) {
            in[viz]--;
            if (in[viz] == 0) {
                q.push(viz);
            }
        }
    }
    if (res.size() != n) cout << "IMPOSSIBLE" << endl;
    else {
        for (auto el : res) {
            cout << el+1 << endl;
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}