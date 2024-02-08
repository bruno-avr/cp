#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

set<pair<int, int>> edges;
vector<int> graph[MAXN];

void dfs(vector<bool> &visited, int u) {
    visited[u] = true;

    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            edges.erase({u, v});
            edges.erase({v, u});
            dfs(visited, v);
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<bool> visited(n, false);
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        
        edges.insert({a, b});
        edges.insert({b, a});
    }
    
    vector<int> alones;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(visited, i);
            alones.push_back(i);
        }
    }

    int numEdges = edges.size()/2;
    if (numEdges >= alones.size()-1) {
        cout << alones.size()-1 << endl;
        for (int i = 1; i < alones.size(); i++) {
            auto it = edges.begin();
            cout << (*it).first+1 << " " << (*it).second+1 << " " << alones[i]+1 << " " << alones[0]+1 << endl;
            edges.erase({(*it).first, (*it).second});
            edges.erase({(*it).second, (*it).first});
        }
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}