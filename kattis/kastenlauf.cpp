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

int dist(vector<pair<int,int>> &coords, int i, int j) {
    return abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second);
}

void solve() {
    int n;
    cin >> n; n+=2;

    vector<pair<int,int>> coords;
    int x, y;
    f(i,0,n) {
        cin >> x >> y;
        coords.push_back({x,y});
    }

    vector<vector<int>> adj(n, vector<int>(n, 0));
    f(i,0,n) f(j,0,n) {
        if (dist(coords, i, j) <= 50*20) {
            adj[i][j] = 1;
        }
    }
    f(k,0,n) f(i,0,n) f(j,0,n) {
        adj[i][j] |= adj[i][k] & adj[k][j];
    }

    if (adj[0][n-1]) {
        cout << "happy" << endl;
    } else {
        cout << "sad" << endl;
    }
}

int main() {
    optimize;
    int T; cin >> T;
    while (T--) solve();

    return 0;
}