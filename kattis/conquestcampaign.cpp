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
    int r, c, n;
    cin >> r >> c >> n;
    bool visited[r][c];
    memset(visited, 0, sizeof visited);
    queue<tuple<int,int,int>> q;
    f(i,0,n) {
        int a, b;
        cin >> a >> b; a--; b--;
        if (!visited[a][b]) {
            q.push({a, b, 1});
            visited[a][b] = 1;
        }
    }
    int res;
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    while (!q.empty()) {
        auto [a, b, level] = q.front(); q.pop();
        res = level;
        for (int i = 0; i < 4; i++) {
            int newA = a + dx[i];
            int newB = b + dy[i];
            if (newA < 0 or newA >= r) continue;
            if (newB < 0 or newB >= c) continue;
            if (visited[newA][newB]) continue;
            q.push({newA, newB, level + 1});
            visited[newA][newB] = 1;
        }
    }
    cout << res << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}