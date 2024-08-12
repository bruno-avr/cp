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
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> v(h, vector<ll>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, 0));
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> v[i][j];
        }
    }
    ll drainI, drainJ;
    cin >> drainI >> drainJ; drainI--; drainJ--;
    
    priority_queue<tuple<ll,ll,ll>> q;
    q.push({-v[drainI][drainJ], drainI, drainJ});

    ll total = 0;
    while(!q.empty()) {
        auto [val, posI, posJ] = q.top(); q.pop();
        val *= -1;
        if (visited[posI][posJ]) continue;
        if (val >= 0) break;
        visited[posI][posJ] = 1;
        total += -val;
        ll dx[] = {-1,-1,-1,0,0,1,1,1};
        ll dy[] = {-1,0,1,-1,1,-1,0,1};
        for (ll i = 0; i < 8; i++) {
            ll nI = posI+dx[i];
            ll nJ = posJ+dy[i];
            if (nI < 0 or nI >= h) continue;
            if (nJ < 0 or nJ >= w) continue;
            if (!visited[nI][nJ]) {
                q.push({min(-val, -v[nI][nJ]), nI, nJ});
            }
        }
    }
    cout << total << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}