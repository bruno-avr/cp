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

const ll MAX = 10010;

ll d[MAX];
vector<tuple<ll,ll,ll,ll>> g[MAX];

ll n;

void dijkstra(ll v) {
    for (ll i = 0; i < n; i++) d[i] = INFLL;
    d[v] = 0;
    priority_queue<pair<ll, ll>> pq;
    pq.emplace(0, v);

    while (pq.size()) {
        auto el = pq.top(); pq.pop();
        auto ndist = -el.first;
        auto u = el.second;
        if (ndist > d[u]) continue;

        for (auto el2 : g[u]) {
            auto idx = get<0>(el2);
            auto t0 = get<1>(el2);
            auto p = get<2>(el2);
            auto de = get<3>(el2);
            ll w = de;
            if (ndist <= t0) {
                w += t0 - ndist;
            } else {
                if (p == 0) continue;
                w += (p - ((ndist - t0) % p)) % p;
            }
            if (d[idx] > d[u] + w) {
                d[idx] = d[u] + w;
                pq.emplace(-d[idx], idx);
            }
        }
    }
}

ll m, q, s;
void solve() {
    for (ll i = 0; i < n; i++) g[i].clear();
    ll u, v, t0, p, de;
    for (ll i = 0; i < m; i++) {
        cin >> u >> v >> t0 >> p >> de;
        g[u].push_back({v,t0,p,de});
    }
    dijkstra(s);
    ll val;
    for (ll i = 0; i < q; i++) {
        cin >> val;
        if (d[val] == INFLL) {
            cout << "Impossible" << endl;
        } else {
            cout << d[val] << endl;
        }
    }
}

int main() {
    optimize;
    bool first = 1;
    while (cin >> n >> m >> q >> s, n) {
        if (first) first = 0;
        else cout << endl;
        solve();
    }

    return 0;
}