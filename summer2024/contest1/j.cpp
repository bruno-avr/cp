#include "bits/stdc++.h"

#define ll long long

using namespace std;

int numRestaurants = 0;
int maxNum;
vector<bool> visited(500000, false);
vector<int> parentId(500000, false);
vector<int> res;

void dfs(vector<vector<int>> &v, int x, int parent) {
    parentId[x] = parent;
    visited[x] = true;

    for (auto viz : v[x]) {
        if (res.size()) return;
        if (!visited[viz]) {
            dfs(v, viz, x);
        } else if (viz != parent) {
            res.push_back(viz);
            res.push_back(x);
            int curr = x;
            while(true) {
                curr = parentId[curr];
                res.push_back(curr);
                if (curr == viz) break;
            }
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> v(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b; a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(v, i, i);
    }

    if (!res.size()) cout << "IMPOSSIBLE" << endl;
    else {
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            if (i != 0) cout << " ";
            cout << res[i]+1;
        }
        cout << endl;
    }

    return 0;
}