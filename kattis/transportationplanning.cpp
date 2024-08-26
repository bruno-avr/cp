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

int n;
ld eps = 1e-9;

ld getVal(vector<pair<ld,ld>> &pos, int x, int y) {
    auto &[x1, y1] = pos[x];
    auto &[x2, y2] = pos[y];

    return sqrtl((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

ld add(vector<vector<ld>> &adj, vector<pair<ld,ld>> &pos, int x, int y) {
    ld res = 0;
    ld cost = getVal(pos,x,y);
    f(i,0,n) f(j,i+1,n) {
        res += min(adj[i][j], (min(adj[i][x] + cost + adj[y][j], adj[i][y] + cost + adj[x][j])));
    }
    return res;
}

void solve() {
    int x, y, m;
    vector<pair<ld,ld>> pos;
    vector<vector<ld>> adj(n, vector<ld>(n, INF));
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        pos.push_back({x, y});
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x][y] = adj[y][x] = getVal(pos, x, y);
    }
    f(i,0,n) adj[i][i] = 0;

    f(k,0,n) f(i,0,n) f(j,0,n) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    }

    ld res1 = 0;
    f(i,0,n) f(j,i+1,n) {
        res1 += adj[i][j];
    }
    if (m == (n*(n-1))/2) {
        cout << fixed << setprecision(10) << "no addition reduces " << res1 << endl;
        return;
    }

    ld minVal = INF;
    f(i,0,n) f(j,i+1,n) {
        ld curr = add(adj,pos,i,j);
        // cout << curr << " " << (curr < minVal) <<  endl;
        if (curr < minVal) {
            minVal = curr;
            // cout << "minVal: " << minVal << endl;
            x = i;
            y = j;
        }
    }

    cout << fixed << setprecision(10) << "adding " << x << " " << y << " reduces " << res1 << " to " << minVal << endl;
}

int main() {
    optimize;
    while (cin >> n, n) solve();

    return 0;
}