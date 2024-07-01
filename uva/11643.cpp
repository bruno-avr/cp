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
#define LSOne(S) ((S)&(-(S)))
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int dx[] = {-1,-2,-2,-1, 1, 2, 2, 1};
int dy[] = {-2,-1, 1, 2,-2,-1, 1, 2};

const int BSIZE = 2010;
const int MIDDLE = 1005;

int base[BSIZE][BSIZE];

int adj[17][17];
int memo[17][1<<16];

int tsp(int curr, int val) {
    int &res = memo[curr][val];
    if (val == 0) return res = adj[curr][0];
    
    if (res != -1) return res;
    res = INF;
    for (int i = val; i > 0; i -= LSOne(i)) {
        int next = __builtin_ctz(i) + 1;
        int nextVal = val - (1<<(next-1));
        res = min(res, tsp(next, nextVal) + adj[curr][next]);
    }
    return res;
}

void solve() {
    memset(memo, -1, sizeof memo);
    int n, k, r, c;
    cin >> n >> k;

    vector<pair<int,int>> v(k);
    f(i,0,k) {
        cin >> r >> c; r--; c--;
        v[i] = {r, c};
    }
    f(i,0,k) {
        f(j,0,k) {
            if (i == j) { adj[i][j] = 0; continue; }
            // cout << "ij: " << i << " " << j << endl;
            int rDiff = MIDDLE - v[i].first;
            int cDiff = MIDDLE - v[i].second;
            int minDist = INF;
            f(l,0,8) {
                int newX = v[j].first + dx[l];
                int newY = v[j].second + dy[l];
                if (newX < 0 or newX >= n) continue;
                if (newY < 0 or newY >= n) continue;
                // cout << newX << " " << newY << " " << base[newX+rDiff][newY+cDiff] << endl;
                minDist = min(minDist, base[newX+rDiff][newY+cDiff] + 1);
            }
            // cout << i << " " << j << " " << minDist << endl;
            adj[i][j] = minDist;
        }
    }

    cout << tsp(0, (1<<(k-1))-1) << endl;
}

int main() {
    optimize;
    queue<tuple<int,int,int>> q;
    bool visited[BSIZE][BSIZE];
    memset(visited, 0, sizeof visited);
    q.push({MIDDLE, MIDDLE, 0});
    visited[MIDDLE][MIDDLE] = 1;
    while(!q.empty()) {
        auto [x, y, dist] = q.front(); q.pop();
        base[x][y] = dist;
        for (int i = 0; i < 8; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 or newX >= BSIZE) continue;
            if (newY < 0 or newY >= BSIZE) continue;
            if (!visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({newX, newY, dist + 1});
            }
        }
    }
    int T; cin >> T;
    int c = 1;
    while (T--) {
        cout << "Case " << c++ << ": ";
        solve();
    }

    return 0;
}