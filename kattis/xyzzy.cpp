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

const int MAX = 110;
int n, m;
int d[MAX];
vector<pair<int, int>> ar; // vetor de arestas
vector<int> w;              // peso das arestas

bool bellman_ford(int a) {
	for (int i = 0; i < n; i++) d[i] = INF;
	d[a] = 0;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < m; j++) {
			if (d[ar[j].second] > d[ar[j].first] + w[j]) {
                if (d[ar[j].first] + w[j] >= 100) continue;
				if (i == n) return 1;

				d[ar[j].second] = d[ar[j].first] + w[j];
			}
		}

	return 0;
}

unordered_set<int> visited;
queue<int> q;
void bellman_ford2() {
    for (int j = 0; j < m; j++) {
        if (d[ar[j].second] > d[ar[j].first] + w[j]) {
            if (d[ar[j].first] + w[j] >= 100) continue;
            
            q.push(ar[j].second);
            visited.insert(ar[j].second);
        }
    }
}

void addEdge(int st, int end, int t) {
    m++;
    ar.push_back({st,end});
    w.push_back(t);
}

void solve() {
    ar.clear();
    w.clear();
    m = 0;
    int nviz;
    vector<int> energy(n);
    vector<vector<int>> viz(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> energy[i] >> nviz;
        viz[i].assign(nviz, 0);
        f(j,0,nviz) {
            cin >> viz[i][j]; viz[i][j]--;
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto el : viz[i]) {
            addEdge(i, el, -energy[el]);
            g[i].push_back(el);
        }
    }
    if (bellman_ford(0)) {
        if (d[n-1] < 100) cout << "winnable" << endl;
        else {
            visited.clear();
            bellman_ford2();
            while (!q.empty()) {
                auto curr = q.front(); q.pop();
                for (auto vizi : g[curr]) {
                    if (visited.count(vizi) == 0) {
                        q.push(vizi);
                        visited.insert(vizi);
                    }
                }
            }
            if (visited.count(n-1)) cout << "winnable" << endl;
            else cout << "hopeless" << endl;
        }
    } else {
        if (d[n-1] < 100) cout << "winnable" << endl;
        else cout << "hopeless" << endl;
    }
}

int main() {
    optimize;
    while(cin >> n, n != -1) solve();

    return 0;
}