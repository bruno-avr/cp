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

int h, w;
ll d[10010];
ll d2[10010];
vector<pair<int, int>> g[10010]; // {vizinho, peso}
vector<pair<int, int>> gInv[10010]; // {vizinho, peso}

int n;
 
void dijkstra(int v) {
	for (int i = 0; i < n; i++) d[i] = INF;
	d[v] = 0;
	priority_queue<pair<ll, int>> pq;
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
 
void dijkstra2(int v) {
	for (int i = 0; i < n; i++) d2[i] = INF;
	d2[v] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.emplace(0, v);
 
	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > d2[u]) continue;
 
		for (auto [idx, w] : gInv[u]) if (d2[idx] > d2[u] + w) {
			d2[idx] = d2[u] + w;
			pq.emplace(-d2[idx], idx);
		}
	}
}
vector<vector<int>> v;
vector<int> res;
void dfs(int u, int rem) {
    res.push_back(u);
    for (auto viz : g[u]) {
        if (rem - viz.second == d2[viz.first]) {
            dfs(viz.first, rem - viz.second);
            break;
        }
    }
}

void solve() {
    char c;
    n = 0;
    f(i,0,10010) g[i].clear();
    f(i,0,10010) gInv[i].clear();
    res.clear();
    map<pair<int,int>, int> encode;
    map<int, pair<int,int>> decode;
    v.assign(h, vector<int>(w, 0));
    encode[{-1, -1}] = n;
    decode[n++] = {-1, -1};
    encode[{INF, INF}] = n;
    decode[n++] = {INF, INF};
    f(i,0,h) f(j,0,w) {
        encode[{i, j}] = n;
        decode[n++] = {i, j};
        cin >> c;
        v[i][j] = c - '0';
    }
    int dx[] = {-1,-1,-1,0,0,1,1,1};
    int dy[] = {-1,0,1,-1,1,-1,0,1};
    f(j,0,w) {
        g[encode[{-1,-1}]].push_back({encode[{0,j}], v[0][j]});
        g[encode[{h-1,j}]].push_back({encode[{INF,INF}], 0});
    }
    f(i,0,h) f(j,0,w) {
        f(k,0,8) {
            int a = i+dx[k];
            int b = j+dy[k];
            if (a < 0 or a >= h) continue;
            if (b < 0 or b >= w) continue;
            g[encode[{i,j}]].push_back({encode[{a,b}], v[a][b]});
        }
    }
    dijkstra(encode[{-1, -1}]);
    f(i,0,n) for(auto viz : g[i]) {
        gInv[viz.first].push_back({i, viz.second});
    }
    dijkstra2(encode[{INF, INF}]);
    dfs(encode[{-1, -1}], d[encode[{INF, INF}]]);
    for(auto el : res) {
        auto [a, b] = decode[el];
        if (a == -1 or a == INF) continue;
        v[decode[el].first][decode[el].second] = 0;
    }
    f(i,0,h) {
        f(j,0,w) {
            if (v[i][j] == 0) cout << " ";
            else cout << v[i][j];
        }
        cout << endl;
    }
    cout << endl;
    // cout << d[encode[{INF, INF}]] << endl;
    // cout << d2[encode[{-1, -1}]] << endl;
}

int main() {
    optimize;
    while(cin >> h >> w, h) solve();

    return 0;
}