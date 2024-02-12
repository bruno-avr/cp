#include "bits/stdc++.h"
#define ll long long

using namespace std;
const int MAXN = 200010;
vector<vector<int>> graph(MAXN);
vector<bool> visited(MAXN, false);
vector<int> profs(MAXN, 0);

int res = 0;

void dfs(int x, int prof) {
    visited[x] = 1;
    profs[x] = prof;
    int profChildren = 0;
    for (auto viz : graph[x]) {
        if (!visited[viz]) {
            dfs(viz, prof+1);
            profs[x] = min(profs[x], profs[viz] + 1);
            profChildren = max(profChildren, profs[viz]);
        }
    }
    if (profChildren > 2) {
        profs[x] = 1;
        res++;
    }
}

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, 0);

    cout << res << endl;
    
    return 0;
}