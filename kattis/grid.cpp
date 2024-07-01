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

vector<vector<int>> g;
vector<vector<bool>> visited;

void solve() {
    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));
    char c;
    f(i,0,n) f(j,0,m) {
        cin >> c;
        g[i][j] = c - '0';
    }

    queue<tuple<int,int,int>> q;
    q.push({0, 0, 0});
    visited[0][0] = true;
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    while (!q.empty()) {
        auto [x, y, level] = q.front(); q.pop();
        if (x == n-1 and y == m-1) {
            cout << level << endl;
            return;
        }
        f(i,0,4) {
            int a = x + dx[i]*g[x][y];
            int b = y + dy[i]*g[x][y];
            if (a < 0 or a >= n) continue;
            if (b < 0 or b >= m) continue;
            if (visited[a][b]) continue;
            q.push({a, b, level + 1});
            visited[a][b] = 1;
        }
    }
    cout << -1 << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}