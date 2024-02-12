#include "bits/stdc++.h"
#define ll long long

using namespace std;
const int MAXN = 200010;
vector<vector<int>> graph(MAXN);
vector<int> tin(MAXN);
vector<bool> visited(MAXN, false);
vector<int> outdegree(MAXN, 0);

int t = 0;

vector<pair<int, int>> res;

void dfs(int x, int parent) {
    visited[x] = 1;
    tin[x] = t++;

    for (auto viz : graph[x]) {
        if (!visited[viz]) {
            dfs(viz, x);
            if (outdegree[viz] % 2 == 0) {
                outdegree[x]++;
                res.push_back({x, viz});
            } else {
                outdegree[viz]++;
                res.push_back({viz, x});
            }
        } else {
            if (viz == parent) continue;
            if (tin[viz] >= tin[parent]) continue;

            outdegree[x]++;
            res.push_back({x, viz});
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; i++) if (!visited[i]) dfs(i, i);

    bool impossible = false;
    for (int i = 0; i < n; i++) if (outdegree[i] % 2 != 0) impossible = true;

    if (impossible) cout << "IMPOSSIBLE" << endl;
    else {
        for (auto el : res) {
            cout << el.first+1 << " " << el.second+1 << endl;
        }
    }
    
    return 0;
}