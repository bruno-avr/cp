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

vector<vector<int>> graph;
vector<int> nviz;
vector<int> totalviz;
vector<bool> visited;

void solve() {
    int c,p,x,l,a,b;
    graph.assign(c, vector<int>());
    nviz.assign(c, 0);
    totalviz.assign(c, 0);
    visited.assign(c, false);
    cin >> c >> p >> x >> l; x--; l--;
    f(i,0,p) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        nviz[a]++;
        nviz[b]++;
        totalviz[a]++;
        totalviz[b]++;
    }
    queue<int> q;
    q.push(l);
    visited[l] = true;
    int res = false;
    while(!q.empty()) {
        auto el = q.front(); q.pop();
        if (el == x) res = true;
        for (auto &viz : graph[el]) {
            if (visited[viz]) continue;
            nviz[viz]--;
            if (((totalviz[viz]+1)/2) <= (totalviz[viz]-nviz[viz])) {
                visited[viz] = true;
                q.push(viz);
            }
        }
    }
    if (res) cout << "leave" << endl;
    else cout << "stay" << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}