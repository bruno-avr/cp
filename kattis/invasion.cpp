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

int n, m, a, k;

const int MAX = 10010;

ll d[MAX];
vector<pair<int, int>> g[MAX]; // {vizinho, peso}

unordered_set<int> safe;
 
void dijkstra(int v) {
    priority_queue<pair<ll, int>> pq;
    d[v] = 0;
    pq.emplace(0, v);
 
    while (pq.size()) {
        auto [ndist, u] = pq.top(); pq.pop();
        if (-ndist > d[u]) continue;
        safe.erase(u);
 
        for (auto [idx, w] : g[u]) if (d[idx] > d[u] + w) {
            if (d[u] + w >= k) continue;
            // if (safe.count(idx) == 0) continue;
            d[idx] = d[u] + w;
            pq.emplace(-d[idx], idx);
        }
    }
}

void solve() {
    f(i,0,n) {
        g[i].clear();
    }
    int t1, t2, dis;
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2 >> dis; t1--; t2--;
        g[t1].push_back({t2, dis});
        g[t2].push_back({t1, dis});
    }
    safe.clear();
    f(i,0,n) {
        safe.insert(i);
    }
    int alien;
    for (int i = 0; i < n; i++) d[i] = INFLL;
    f(i,0,a) {
        cin >> alien; alien--;
        dijkstra(alien);
        cout << safe.size() << endl;
    }
    cout << endl;
}

int main() {
    optimize;
    while (cin >> n >> m >> a >> k, n) solve();

    return 0;
}