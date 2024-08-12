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
    int n, m, v; 
    cin >> n >> m;
    string s1, s2;
    vector<string> target(n);
    unordered_map<string, pair<int, int>> dist;
    f(i,0,n) {
        cin >> target[i];
        dist[target[i]] = {INF, 0};
    }
    unordered_map<string, set<pair<string, int>>> g;
    f(i,0,m) {
        cin >> s1 >> s2 >> v;
        g[s1].insert({s2, v});
        g[s2].insert({s1, v});
    }
    queue<string> q;
    q.push("English");
    dist["English"] = {0, 0};
    unordered_set<string> visited;
    int res = 0;
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        if (visited.count(curr)) continue;
        visited.insert(curr);
        res += dist[curr].second;
        // cout << curr << " " << dist[curr].second << endl;
        for (auto el : g[curr]) {
            string viz = el.first;
            int val = el.second;
            if (dist[viz].first >= dist[curr].first+1) {
                if (dist[viz].first > dist[curr].first+1) {
                    dist[viz] = {dist[curr].first+1, val};
                } else {
                    dist[viz] = {dist[curr].first+1, min(dist[viz].second, val)};
                }
                q.push(viz);
            }
        }
    }
    if (visited.size() - 1 < n) cout << "Impossible" << endl;
    else cout << res << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}