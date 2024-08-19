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

const ll MAX = 1010;

ll n, m;
ll idx;
ll d[MAX];
vector<pair<ll, ll>> ar; // vetor de arestas
vector<ll> graph[MAX];
vector<ll> w;              // peso das arestas
map<pair<ll,ll>, ll> id;
vector<bool> reachable;

void dfs(ll u) {
    reachable[u] = true;
    for (auto viz : graph[u]) {
        if (!reachable[viz]) {
            dfs(viz);
        }
    }
}

bool bellman_ford(ll a) {
	for (ll i = 0; i < n; i++) d[i] = INFLL;
	d[a] = 0;

	for (ll i = 0; i <= n; i++)
		for (ll j = 0; j < m; j++) {
            if (!reachable[ar[j].first] or !reachable[ar[j].second]) continue;
			if (d[ar[j].second] > d[ar[j].first] + w[j]) {
				if (i == n) return 1;

				d[ar[j].second] = d[ar[j].first] + w[j];
			}
		}

	return 0;
}

ll getId(ll x, ll y) {
    if (id.count({x, y})) return id[{x, y}];
    return id[{x, y}] = idx++;
}

void addEdge(ll x, ll y, ll x2, ll y2, ll t) {
    // cout << x << " " << y << " -> " << x2 << " " << y2 << " " << t << endl;
    graph[getId(x, y)].push_back(getId(x2, y2));
    m++;
    ar.push_back({getId(x, y), getId(x2, y2)});
    w.push_back(t);
}

ll wei, hei;
void solve() {
    n = wei*hei;
    id.clear();
    w.clear();
    ar.clear();
    for (int i = 0; i < n; i++) graph[i].clear();
    reachable.assign(n, 0);
    m = idx = 0;
    vector<vector<ll>> mat(wei, vector<ll>(hei, 0));
    ll g; cin >> g;
    ll x, y, x2, y2, t;
    f(i,0,g) {
        cin >> x >> y;
        mat[x][y] = 1;
    }
    ll e; cin >> e;
    f(i,0,e) {
        cin >> x >> y >> x2 >> y2 >> t;
        mat[x][y] = 2;
        addEdge(x, y, x2, y2, t);
    }
    f(i,0,wei) {
        f(j,0,hei) {
            if (mat[i][j] == 2) continue;
            if (i == wei-1 and j == hei-1) continue;
            ll dx[] = {-1,1,0,0};
            ll dy[] = {0,0,-1,1};
            f(k,0,4) {
                ll nx = i+dx[k];
                ll ny = j+dy[k];
                if (nx < 0 or nx >= wei) continue;
                if (ny < 0 or ny >= hei) continue;
                if (mat[nx][ny] == 1) continue;
                addEdge(i,j,nx,ny,1);
            }
        }
    }
    dfs(getId(0,0));
    if (bellman_ford(getId(0,0))) {
        cout << "Never" << endl;
    } else {
        // for (ll i = 0; i < n; i++) cout << d[i] << " ";
        if (d[getId(wei-1, hei-1)] >= INFLL) {
            cout << "Impossible" << endl;
        } else {
            cout << d[getId(wei-1, hei-1)] << endl;
        }
    }
}

int main() {
    optimize;
    while(cin >> wei >> hei, wei) solve();

    return 0;
}