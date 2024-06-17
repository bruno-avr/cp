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

const ll MAXN = 200010;
vector<vector<int>> graph(MAXN);
vector<vector<int>> reverseGraph(MAXN);
vector<int> visited(MAXN);
vector<int> exitOrder;
vector<int> componentOfV(MAXN);
vector<unordered_set<int>> condensationGraphEdges(MAXN);
vector<vector<int>> condensationGraph(MAXN);
vector<vector<int>> components;

void init(int numV, int numE) {
    exitOrder.clear();
    components.clear();
    for (int i = 0; i < numV; i++) {
        graph[i].clear();
        reverseGraph[i].clear();
        condensationGraph[i].clear();
        condensationGraphEdges[i].clear();
        visited[i] = 0;
    }
}

void dfs(int v) {
    visited[v] = 1;

    for (int u : graph[v]) if (visited[u] != 1) dfs(u);

    exitOrder.push_back(v);
}

void dfs2(int v, int c) {
    visited[v] = 2;
    componentOfV[v] = c;
    components.back().push_back(v);

    for (int u : reverseGraph[v]) if (visited[u] != 2) dfs2(u, c);
}

void dfs3(int v) {
    visited[v] = 3;

    for (int u : graph[v]) {
        if (componentOfV[v] != componentOfV[u]) {
            condensationGraphEdges[componentOfV[v]].insert(componentOfV[u]);
        }
        if (visited[u] != 3) dfs3(u);
    }
}

void createCondensationGraph(int n) {
    for (int i = 0; i < n; i++) if(visited[i] == 2) dfs3(i);

    for (int i = 0; i < components.size(); i++) {
        condensationGraph[i].insert(condensationGraph[i].end(), condensationGraphEdges[i].begin(), condensationGraphEdges[i].end());
    }
}

int countLeaves(int u) {
    visited[u] = 1;
    int numLeaves = 0;
    if (condensationGraph[u].size() == 0) return 1;
    for (auto viz : condensationGraph[u]) {
        if (visited[viz] == 0) {
            numLeaves += countLeaves(viz);
        }
    }
    return numLeaves;
}

void solve() {
    ll n, m, a, b;
    cin >> n >> m;
    init(n, m);

    for (ll i = 0; i < m; i++) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        reverseGraph[b].push_back(a);
    }

    for (int i = 0; i < n; i++) if(visited[i] == 0) dfs(i);

    int componentId = 0;
    for (int i = exitOrder.size()-1; i >= 0; i--) if(visited[exitOrder[i]] == 1) {
        components.push_back(vector<int>());
        dfs2(exitOrder[i], componentId++);
    }

    createCondensationGraph(n);

    if (components.size() == 1) {
        cout << 0 << endl;
        return;
    }

    vector<int> in(components.size(), 0);
    int out = 0, ins = 0;
    for (int i = 0; i < components.size(); i++) {
        for (auto &viz : condensationGraph[i]) {
            in[viz]++;
        }
        if (condensationGraph[i].size() == 0) {
            out++;
            // cout <<"a" << i << endl;
        }
    }
    for (int i = 0; i < components.size(); i++) {
        if (in[i] == 0) ins++;
    }

    cout << max(out, ins) << endl;
    // cout << "Condensation graph num of vertices: " << components.size() << endl;
    // for (int i = 0; i < components.size(); i++) {
    //     for (int j = 0; j < condensationGraph[i].size(); j++) {
    //         cout << "(" << i+1 << ", " << condensationGraph[i][j]+1 << ") ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;
}

// const int MAX = 100010;
// int n;
// vector<int> g[MAX];
// vector<int> gi[MAX]; // grafo invertido
// int vis[MAX];
// stack<int> S;
// int comp[MAX]; // componente conexo de cada vertice
// bool visited[MAX];
// vector<int> aux;
// unordered_map<int, int> aux2;

// void dfs(int k) {
// 	vis[k] = 1;
// 	for (int i = 0; i < (int) g[k].size(); i++)
// 		if (!vis[g[k][i]]) dfs(g[k][i]);

// 	S.push(k);
// }

// void scc(int k, int c) {
// 	vis[k] = 1;
// 	comp[k] = c;
//     aux2[c] = k;
// 	for (int i = 0; i < (int) gi[k].size(); i++)
// 		if (!vis[gi[k][i]]) scc(gi[k][i], c);
// }
// void kosaraju() {
// 	for (int i = 0; i < n; i++) vis[i] = 0;
// 	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

// 	for (int i = 0; i < n; i++) vis[i] = 0;
// 	while (S.size()) {
// 		int u = S.top();
// 		S.pop();
// 		if (!vis[u]) {
//             scc(u, u);
//             aux.push_back(u);
//         }
// 	}
// }

// unordered_map<int, unordered_set<int>> newG;
// void dfs2(int u) {
//     visited[u] = 1;
//     newG[comp[u]];
//     for (auto viz : g[u]) {
//         if (!visited[viz]) {
//             dfs2(viz);
//         }
//         if (comp[viz] != comp[u]) {
//             newG[comp[u]].insert(comp[viz]);
//         }
//     }
// }
// int dfs3(int u) {
//     visited[u] = 1;
//     int res = true;
//     int numLeaves = 0;
//     if (newG[u].size() == 0) return 1;
//     for (auto viz : newG[u]) {
//         if (visited[viz] == 0) {
//             numLeaves += dfs3(viz);
//         }
//     }
//     return numLeaves;
// }

// void solve() {
//     memset(visited, 0, sizeof visited);
//     memset(vis, 0, sizeof vis);
//     for (int i = 0; i < n; i++) {
//         g[i].clear();
//         gi[i].clear();
//     }
//     aux.clear();
//     aux2.clear();
//     newG.clear();
//     int m, x, y;
//     cin >> n >> m;
//     f(i,0,m) {
//         cin >> x >> y; x--; y--;
//         g[x].push_back(y);
//         gi[y].push_back(x);
//     }
//     kosaraju();
//     int res = 0;
//     memset(visited, 0, sizeof visited);
//     for (auto el : aux) {
//         // cout << "b" << el << endl;
//         // cout << aux2[el] << endl;
//         if (!visited[el]) {
//             dfs2(el);
//         }
//     }
//     // cout << newG.size() << endl;
//     // memset(visited, 0, sizeof visited);
//     // for (auto el : aux) {
//     //     // cout << aux2[el] << endl;
//     //     if (!visited[comp[aux2[el]]]) {
//     //         int numLeaves = dfs3(comp[aux2[el]]);
//     //         // cout << "nl" << aux2[el] << " " << numLeaves << endl;
//     //         res+=max(1, numLeaves);
//     //     }
//     // }
//     int c1 = comp[0];
//     f(i,1,n) {
//         if (comp[i] != c1) {
//             c1 = -1;
//             break;
//         }
//     }
//     if (c1 != -1) {
//         cout << 0 << endl; 
//         return;
//     }
//     unordered_map<int, int> in;
//     int out = 0, ins = 0;
//     for (auto el : aux) {
//         int i = comp[el];
//         for (auto &viz : newG[i]) {
//             in[viz]++;
//         }
//         if (newG[i].size() == 0) {
//             out++;
//             // cout <<"a" << i << endl;
//         }
//     }
//     for (auto el : aux) {
//         int i = comp[el];
//         if (in[i] == 0) ins++;
//     }

//     cout << max(out, ins) << endl;
//     // cout << max(out, ins) << " " << out << " " << ins << endl;
//     // cout << res << endl; 
// }

int main() {
    optimize;
    int T; cin >> T;
    while (T--) solve();

    return 0;
}