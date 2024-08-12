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
    int w, h;
    cin >> h >> w;
    vector<vector<char>> v(w, vector<char>(h));
    queue<tuple<int,int,char,int>> q;
    int p1, p2;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cin >> v[i][j];
            if (v[i][j] == '*') {
                q.push({i, j, '*', 0});
            } else if (v[i][j] == '@') {
                p1 = i;
                p2 = j;
                v[i][j] = '#';
            }
        }
    }
    q.push({p1, p2, '@', 0});
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    while (!q.empty()) {
        auto [i, j, type, dist] = q.front(); q.pop();
        // if (type == '@') {
        //     cout << i << " " << j << endl;
        // }
        for (int y = 0; y < 4; y++) {
            if ((i + dx[y] < 0) or (i + dx[y] >= w) or (j + dy[y] < 0) or (j + dy[y] >= h)) {
                if (type == '@') {
                    cout << dist+1 << endl;
                    return;
                }
                continue;
            }
            auto &pos = v[i + dx[y]][j + dy[y]];
            if (pos == '.') {
                if (type == '*') {
                    pos = '*';
                    q.push({i + dx[y], j + dy[y], '*', dist+1});
                } else {
                    pos = '#';
                    q.push({i + dx[y], j + dy[y], '@', dist+1});
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    optimize;
    int T; cin >> T;
    while (T--) solve();

    return 0;
}