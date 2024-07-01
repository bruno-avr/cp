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

// Dijkstra
//
// encontra menor distancia de x
// para todos os vertices
// se ao final do algoritmo d[i] = LINF,
// entao x nao alcanca i
//
// O(m log(n))
const int MAX = 1010;
map<set<int>, int> ii_to_i;
map<int, pair<int,int>> i_to_ii;
int idx = 0;
ll d[MAX][100];
vector<pair<int, int>> g[MAX]; // {vizinho, peso}
vector<int> price;

int n;
int cap, s, e;
int getId(int a, int b) {
    if (ii_to_i.count({a,b})) return ii_to_i[{a,b}];
    return ii_to_i[{a,b}] = idx++;
}
 
void dijkstra() {
	for (int i = 0; i < n; i++)
	    for (int j = 0; j <= cap; j++) d[i][j] = INF;
	d[s][0] = 0;
	priority_queue<tuple<ll, int, int>> pq;
	pq.emplace(0, s, 0);
 
	while (pq.size()) {
		auto [ndist, u, val] = pq.top(); pq.pop();
        // cout << -ndist << " " << u << " " << val << endl;
        if (u == e) {
            cout << -ndist << endl;
            return;
        }
        // cout << "here " << d[u][val] << endl;
		if (-ndist > d[u][val]) continue;

        if (val + 1 <= cap) {
            d[u][val+1] = -ndist + price[u];
            pq.emplace(ndist - price[u], u, val+1);
        }

		for (auto [idx, w] : g[u]) if (w <= val) {
            // cout << "here" << d[idx][val-w] << " " << d[u][val] << endl;
            if (d[idx][val-w] > d[u][val]) {
                d[idx][val-w] = d[u][val];
                pq.emplace(-d[idx][val-w], idx, val-w);
            }
        }
	}
    cout << "impossible" << endl;
}

void solve() {
    int m, a, b, w, q, p;
    cin >> n >> m;
    f(i,0,n) {
        cin >> p;
        price.push_back(p);
    }
    f(i,0,m) {
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    cin >> q;
    
    f(i,0,q) {
        cin >> cap >> s >> e;
        dijkstra();
    }
}

int main() {
    optimize;
    solve();

    return 0;
}