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
    int n, a, b;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    vector<pair<int,int>> v(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        v[i] = {a, b};
    }

    queue<pair<int,int>> bfs;
    bfs.push({0, 0});
    visited[0] = true;
    map<pair<int,int>, pair<int,int>> mp;
    while(!bfs.empty()) {
        auto curr = bfs.front(); bfs.pop();
        for (auto viz : graph[curr.first]) {
            if (!visited[viz]) {
                bfs.push({viz, 1-curr.second});
                visited[viz] = true;
                if (curr.second == 0) {
                    mp[{curr.first, viz}] = {viz, curr.first};
                    mp[{viz, curr.first}] = {viz, curr.first};
                } else {
                    mp[{curr.first, viz}] = {curr.first, viz};
                    mp[{viz, curr.first}] = {curr.first, viz};
                }
            }
        }
    }

    // queue<int> q;
    // vector<int> in(n,0);
    // for (int i = 0; i < n; i++) {
    //     in[i] = graph[i].size();
    //     if (graph[i].size() == 1) q.push(i), visited[i] = true, in[i]=0;
    // }
    // map<pair<int,int>, pair<int,int>> mp;
    // while(!q.empty()) {
    //     int curr = q.front(); q.pop();
    //     for (auto viz : graph[curr]) {
    //         if (in[viz] != 0) {
    //             mp[{curr, viz}] = {viz, curr};
    //             mp[{viz, curr}] = {viz, curr};
    //             q.push(viz);
    //             in[viz]--;
    //         } else if (graph[curr].size() == 1 && graph[viz].size() == 1) {
    //             mp[{curr, viz}] = {viz, curr};
    //             mp[{viz, curr}] = {viz, curr};
    //         }
    //     }
    // }
    for (int i = 0; i < n-1; i++) {
        if (mp[{v[i].first, v[i].second}] == make_pair(v[i].first, v[i].second)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}