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

const ll MAX = 1000;

ll d[MAX];
vector<pair<ll, ll>> g[MAX]; // {vizinho, peso}

ll n, m;
 
void dijkstra(vector<ll> &startingVertices) {
	for (ll i = 0; i < n; i++) d[i] = INFLL;
	priority_queue<pair<ll, ll>> pq;
    for (auto el : startingVertices) {
        d[el] = 0;
	    pq.emplace(0, el);
    }
 
	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > d[u]) continue;
 
		for (auto [idx, w] : g[u]) if (d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.emplace(-d[idx], idx);
		}
	}
}

void solve() {
    ll fs, a, b, w;
    cin >> fs >> n;
    f(i,0,n) g[i].clear();
    vector<ll> startingVertices(fs);
    f(i,0,fs) {
        cin >> a; a--;
        startingVertices[i] = a;
    }
    string line;
    cin.ignore();
    while(getline(cin, line)) {
        if (line == "") break;
        stringstream ss;
        ss << line;
        ss >> a >> b >> w; a--; b--;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    ll maxRes = INF, maxIndex;
    for (ll i = 0; i < n; i++) {
        startingVertices.push_back(i);
        dijkstra(startingVertices);
        startingVertices.pop_back();

        ll maxDist = -1, index;
        f(j,0,n) {
            if (d[j] > maxDist) {
                maxDist = d[j];
                index = j;
            }
        }
        if (maxDist < maxRes) {
            maxRes = maxDist;
            maxIndex = i;
        }
    }
    cout << maxIndex+1 << endl;
}

int main() {
    optimize;
    ll T; cin >> T;
    while (T--) {
        solve();
        if (T) cout << endl;
    }

    return 0;
}