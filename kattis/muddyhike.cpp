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

#define f(i,s,e) for(int i=s;i<e;i++)
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;                                  // the graph stored in AL
vi taken;                                        // to avoid cycle
priority_queue<tuple<int,int,int>> pq;                           // to select shorter edges
// C++ STL priority_queue is a max heap, we use -ve sign to reverse order

void process(int u) { // set u as taken and enqueue neighbors of u
  taken[u] = 1;
  for (auto &[v, w] : AL[u])
    if (!taken[v])
      pq.push({-w, u, v});                         // sort by non-dec weight
}    

int n, m;

bool visited[1000010];
int res = 987654321;
int memo[1000010];
bool dfs(vector<vector<int>> &g, int x, vector<vector<int>> &v, int maxV) {
    visited[x] = true;
    if (v[x/m][x%m] > maxV) return false;
    // cout << x << endl;
    if (x%m == m-1) {
        return true;
    }
    for (auto viz : g[x]) {
        // cout << "viz" << viz << endl;
        if (!visited[viz]) {
            if (dfs(g, viz, v, maxV)) return true;
        }
    }
    return false;
}

bool p(vector<vector<int>> &tree, vector<vector<int>> &v, int x) {
    memset(visited, 0, sizeof visited);
    f(i,0,n) {
        // cout << "a" << i*m << endl;
        if (!visited[i*m])
        if (dfs(tree, i*m, v, x)) return true;
    }
    return false;
}

int bs(vector<vector<int>> &tree, vector<vector<int>> &v) {
    int l = 0;
    int r = 1000000;
    while(l<r) {
        int m = l + (r-l)/2;

        p(tree, v, m) ? r = m : l = m+1;
    }
    return p(tree, v, l) ? l : -1;
}

void solve() {
    memset(memo, -1, sizeof memo);
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    f(i,0,n) f(j,0,m) {
        cin >> v[i][j];
    }
    AL.assign(n*m, vii());
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    f(i,0,n) f(j,0,m) {
        f(k,0,4) {
            if (i + dx[k] < 0 or i + dx[k] >= n) continue;
            if (j + dy[k] < 0 or j + dy[k] >= m) continue;
            int x = i*m+j;
            int y = (i + dx[k])*m+(j + dy[k]);
            int w = max(v[i + dx[k]][j + dy[k]], v[i][j]);
            AL[x].emplace_back(y, w);
            // cout << i << " " << j << endl;
            // cout << x << " " << y << " " << w << " - " << v[i + dx[k]][j + dy[k]] << " " << v[i][j] << endl;
        }
    }
    taken.assign(n*m, 0);                            // no vertex is taken
    process(0);                                    // take+process vertex 0
    int mst_cost = 0, num_taken = 0;               // no edge has been taken

    vector<vector<int>> tree(n*m);
    while (!pq.empty()) {                          // up to O(E)
        auto [w, u, next] = pq.top(); pq.pop();            // C++17 style
        w = -w;                              // negate to reverse order
        if (taken[next]) continue;                      // already taken, skipped
        mst_cost += w;                               // add w of this edge
        process(next);                                  // take+process vertex u
        ++num_taken;                                 // 1 more edge is taken
        tree[u].push_back(next);
        tree[next].push_back(u);
        if (num_taken == n*m-1) break;                 // optimization
    }

    cout << bs(tree, v) << endl;
    // cout << p(tree, v, 7) << endl;
    // printf("MST cost = %d (Prim's)\n", mst_cost);
}

int main() {
    optimize;
    solve();

    return 0;
}