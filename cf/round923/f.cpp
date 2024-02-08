#include "bits/stdc++.h"

#define ll long long

using namespace std;

const ll MAXN = 200010;
vector<vector<int>> graph(MAXN);
vector<bool> visited(MAXN);
vector<int> pre(MAXN);
vector<int> lowlink(MAXN);
vector<pair<int, int>> bridges;
int entryTime;

void init(int numV, int numE) {
    entryTime = 0;
    bridges.clear();
    for (int i = 0; i < numV; i++) {
        graph[i].clear();
        visited[i] = false;
    }
}

void dfs(int u, int father) {
    visited[u] = true;
    pre[u] = entryTime++;
    lowlink[u] = pre[u];

    for (auto v : graph[u]) {
        if (!visited[v]) {
            dfs(v, u);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        } else {
            if (v == father) continue;
            if (pre[v] >= pre[u]) continue;

            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }

    if (lowlink[u] == pre[u] && u != father) {
        bridges.push_back({u, father});
    }
}

void dfs2(stack<int> &res, vector<bool> &visited2, int u, int end) {
    visited2[u] = true;
    if (res.empty() || res.top() != end) res.push(u);
    if (res.top() == end) return; 
    for (auto v : graph[u]) {
        if (v == end && res.size() == 1) continue;
        if (!visited2[v]) {
            dfs2(res, visited2, v, end);
        }
    }
    if (res.top() != end) res.pop();
}

void solve() {
    ll n, m, a, b, c;
    cin >> n >> m;
    init(n, m);

    set<pair<int, pair<int,int>>> edges;
    map<pair<int,int>, int> w;
    for (ll i = 0; i < m; i++) {
        cin >> a >> b >> c; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges.insert({c, {a, b}});
        edges.insert({c, {b, a}});
        w[{a,b}] = c;
        w[{b,a}] = c;
    }

    for (int i = 0; i < n; i++) if(!visited[i]) dfs(i,i);

    for (auto bridge : bridges) {
        int thisW = w[bridge];
        edges.erase({thisW, bridge});
        edges.erase({thisW, {bridge.second, bridge.first}});
    }

    auto edge = *(edges.begin());

    // int initialV;
    // int endV;
    // if (fathers[edge.second.first] == edge.second.first) {
    //     initialV = edge.second.second;
    //     endV = edge.second.first;
    // } else {
    //     initialV = edge.second.first;
    //     endV = edge.second.second;
    // }

    // vector<int> res;
    // res.push_back(initialV);
    // cout << "i" << initialV << " f" << endV << endl;
    // while(initialV != endV) {
    //     initialV = fathers[initialV];
    //     res.push_back(initialV);
    // }

    vector<bool> visited2(n, false);
    stack<int> res;
    // res.push(edge.second.first);
    dfs2(res, visited2, edge.second.first, edge.second.second);

    cout << edge.first << " " << res.size() << endl;
    while (!res.empty()) {
        cout << res.top()+1;
        res.pop();
        if (!res.empty()) cout << " ";
    }
    cout << endl;        
}

int main() {
    ll t;
    cin >> t;

    while (t--) solve();

    return 0;
}