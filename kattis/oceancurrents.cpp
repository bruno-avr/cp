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

int r, c;
void process(vector<vector<int>> &v) {
    vector<vector<int>> dists(r, vector<int>(c, INF));
    int rs, cs, rd, cd;
    cin >> rs >> cs >> rd >> cd; rs--; cs--; rd--; cd--;
    dists[rs][cs] = 0;
    deque<tuple<int,int,int>> q;
    q.push_back({rs, cs, 0});
    int dx[] = {-1, -1,  0,  1,  1,  1,  0, -1};
    int dy[] = { 0,  1,  1,  1,  0, -1, -1, -1};
    while (!q.empty()) {
        auto el = q.front(); q.pop_front();
        int x = get<0>(el);
        int y = get<1>(el);
        int dist = get<2>(el);
        // cout << x << " " << y << endl;
        if (dist > dists[x][y]) continue;
        if (x == rd and y == cd) {
            cout << dist << endl;
            return;
        }
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 or nx >= r) continue;
            if (ny < 0 or ny >= c) continue;
            // cout << nx << " " << ny << endl;
            if (i == v[x][y]) {
                int newDist = dist;
                if (newDist < dists[nx][ny]) {
                    dists[nx][ny] = newDist;
                    q.push_front({nx, ny, newDist});
                }
            } else {
                int newDist = dist+1;
                if (newDist < dists[nx][ny]) {
                    dists[nx][ny] = newDist;
                    q.push_back({nx, ny, newDist});
                }
            }
        }
    }
}

void solve() {
    cin >> r >> c;
    vector<vector<int>> v(r, vector<int>(c));
    char ch;
    f(i,0,r) f(j,0,c) {
        cin >> ch;
        v[i][j] = ch - '0';
    }
    int n;
    cin >> n;
    // cout << n << endl;
    while(n--) {
        process(v);
    }
}

int main() {
    optimize;
    solve();

    return 0;
}