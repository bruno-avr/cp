#include <bits/stdc++.h>

typedef unsigned long long int ull;

using namespace std;

const ull MAXN = 200010;

vector<ull> graph[MAXN]; vector<ull> edge[MAXN];
ull pre[MAXN], low[MAXN];
bool visited[MAXN], isArticulationPoint[MAXN], edgeVisited[MAXN];
stack<ull> edgesStack;
ull t;
vector<vector<ull>> components;

void init(ull n, ull e) {
    t = 0;
    for (ull i = 0; i < n; i++) {
        graph[i].resize(0);
        edge[i].resize(0);
        visited[i] = false;
        isArticulationPoint[i] = false;
    }
    for (ull i = 0; i < e; i++) {
        edgeVisited[i] = false;
    }
    components.clear();
}

void newBiconnectedComponent (ull edgeId) {
    vector<ull> newComponent;
    ull a;
    do {
        a = edgesStack.top();
        edgesStack.pop();
        newComponent.push_back(a);
        if(edgesStack.empty()) break;
    } while(a != edgeId);
    components.push_back(newComponent);
}

void dfs(ull u) {
    t++;
    pre[u] = t;
    low[u] = t;
    visited[u] = true;

    ull numChildren = 0;
    for (ull i = 0; i < graph[u].size(); i++) {
        ull v = graph[u][i];
        ull edgeId = edge[u][i];

        if (edgeVisited[edgeId]) continue;
        edgeVisited[edgeId] = 1;
        edgesStack.push(edgeId);

        if (!visited[v]) {
            numChildren++;
            dfs(v);
            low[u] = min(low[u], low[v]);
            
            bool foundNewComponent = false;
            if (u == 0 && numChildren >= 2) foundNewComponent = true;
            if (u != 0 && low[v] >= pre[u]) foundNewComponent = true;

            if (foundNewComponent) {
                isArticulationPoint[u] = true;
                newBiconnectedComponent(edgeId);
            }
        } else {
            low[u] = min(low[u], pre[v]);
        }
    }
}

int main() {
    ull t, n, e, a, b, caso = 1;
    cin >> t;
    while (t--) {
        cin >> n >> e;
        init(n, 2*e);
        set<ull> s[n];
        ull total = 1;
 
        for (ull i = 0; i < e; i++) {
            cin >> a >> b; a--; b--;
            if (a == b) continue;
            if (s[a].find(b) != s[a].end() or s[b].find(a) != s[b].end()){
                total*=2;
            } else {
                graph[a].push_back(b);
                graph[b].push_back(a);
                edge[a].push_back(i);
                edge[b].push_back(i);
                s[a].insert(b);
                s[b].insert(a);
            }
        }

        dfs(0);
        newBiconnectedComponent(-1);

        for (auto component : components) {
            total *= component.size();
        }
        
        cout << "Case " << caso++ << ": " << total << endl;
    }



    return 0;
}