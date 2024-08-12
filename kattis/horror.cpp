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
    int n, h, l, a, b;
    cin >> n >> h >> l;
    vector<vector<int>> g(n);
    vector<int> v(n, INF);
    queue<int> q;
    f(i,0,h) {
        cin >> a;
        q.push(a);
        v[a] = 0;
    }
    f(i,0,l) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    while(!q.empty()) {
        auto curr = q.front(); q.pop();
        for (auto viz : g[curr]) {
            if (v[viz] == INF) {
                v[viz] = v[curr] + 1;
                q.push(viz);
            }
        }
    }
    int maxI, maxV = -1;
    f(i,0,n) {
        if (v[i] > maxV) {
            maxV = v[i];
            maxI = i;
        }
    }
    cout << maxI << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}