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
    int r, c, a, b;
    cin >> r >> c;
    vector<vector<char>> g(r, vector<char>(c));
    f(i,0,r) f(j,0,c) {
        cin >> g[i][j];
    }
    cin >> a >> b; a--; b--;
    int cost = 0;
    deque<tuple<int, int, int>> q;
    q.push_back({a, b, 1});
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    while(!q.empty()) {
        auto [x, y, val] = q.front(); q.pop_front();
        f(i,0,4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 or nx >= r or ny < 0 or ny >= c) {
                cout << val << endl;
                return;
            }
            if (g[nx][ny] == '#') continue;
            if (g[nx][ny] == 'D') q.push_front({nx, ny, val});
            if (g[nx][ny] == 'c') q.push_back({nx, ny, val+1});
            g[nx][ny] = '#';
        }
    }

}

int main() {
    optimize;
    solve();

    return 0;
}