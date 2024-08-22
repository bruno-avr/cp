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

ll n, m, q;

void solve() {
    vector<vector<ll>> am(n, vector<ll>(n, INFLL));

    ll u, v, w;
    f(i,0,n) am[i][i] = 0;
    f(i,0,m) {
        cin >> u >> v >> w;
        am[u][v] = min(am[u][v], w);
    }

    f(k,0,n) f(i,0,n) f(j,0,n) {
        if (am[i][k] != INFLL and am[k][j] != INFLL) am[i][j] = min(am[i][j], am[i][k] + am[k][j]);
    }

    f(i,0,q) {
        cin >> u >> v;
        if (am[u][v] == INFLL) {
            cout << "Impossible" << endl;
        } else {
            bool infinity = 0;
            f(j,0,n) {
                if (am[j][j] < 0 and (am[u][j] != INFLL) and (am[j][v] != INFLL)) infinity = 1;
            }
            if (infinity) {
                cout << "-Infinity" << endl;
            } else {
                cout << am[u][v] << endl;
            }
        }
    }
    cout << endl;
}

int main() {
    optimize;
    while(cin >> n >> m >> q, n) solve();

    return 0;
}