#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
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

const ll MAX = 2510;
ll d[MAX];
vector<pair<ll, ll>> g[MAX]; // {vizinho, peso}

ll n;
ll n2;
 
void dijkstra(ll v) {
	for (ll i = 0; i < n2; i++) d[i] = INFLL;
	d[v] = 0;
	priority_queue<pair<ll, ll>> pq;
	pq.emplace(0, v);
 
	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > d[u]) continue;
 
		for (auto [idx, w] : g[u]) if (d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.emplace(-d[idx], idx);
		}
	}
}

bool cmp(ll a, ll b) {
    return a == b;
}

ll powlaa(ll a, ll a2) {
    return a * a;
}

void solve() {
    cin >> n;
    n2 = n+2;
    vector<pair<ll,ll>> v(n2);
    ll a, b;
    f(i,0,n2) {
        cin >> a >> b;
        v[i] = {a,b};
    }
    f(i,0,n2) {
        f(j,0,n2) {
            ll dist = powlaa(abs(v[i].first - v[j].first), 2) + powlaa(abs(v[i].second - v[j].second), 2);
            g[i].push_back({j, dist});
            // cout << dist << " ";
        }
        // cout << endl;
    }
    dijkstra(n+1);
    vector<ll> res;
    ll curr = n;
    vector<bool> visited(n2, 0);
    visited[curr] = true;
    while (curr != n+1) {
        bool found = 0;
        f(i,0,n2) {
            if (i == curr) continue;
            ll dist = powlaa(abs(v[i].first - v[curr].first), 2) + powlaa(abs(v[i].second - v[curr].second), 2);
            if (cmp(d[i] + dist, d[curr])) {
                if (visited[i]) continue;
                visited[i] = 1;
                found = 1;
                // cout << i << " " << d[i] << " " << d[curr] << " " << dist << " " << endl;
                curr = i;
                res.push_back(i);
                break;
            }
        }
    }
    res.pop_back();
    if (res.size() == 0) {
        cout << "-" << endl;
    } else {
        for (auto el : res) {
            cout << el << endl;
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}