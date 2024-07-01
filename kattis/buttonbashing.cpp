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
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    queue<int> q;
    q.push(0);
    vector<int> visited(3700, 0);
    visited[0] = 1;
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        for (auto el : v) {
            int next = curr + el;
            next = max(0, next);
            next = min(3600, next);
            if (!visited[next]) {
                visited[next] = visited[curr]+1;
                q.push(next);
            }
        }
    }
    for (int i = t; i <= 3600; i++) {
        if (visited[i] != 0) {
            cout << visited[i]-1 << " " << i-t << endl;
            break;
        }
    }
}

int main() {
    optimize;
    int T; cin >> T;
    while (T--) solve();

    return 0;
}