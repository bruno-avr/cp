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
vector<vector<bool>> graph;
vector<vector<bool>> visited;
vector<vector<int>> component;
int r, c;

int dr[] = { 0, 0, 1, -1 };            // the order is:
int dc[] = { 1, -1, 0, 0 };            // S/SE/E/NE/N/NW/W/SW

void dfs(int i, int j, int compId) {
    component[i][j] = compId;
    visited[i][j] = true;
    for (int d = 0; d < 4; ++d) {
        int newI = i+dr[d], newJ = j+dc[d];
        if (newI < 0 or newI >= r) continue;
        if (newJ < 0 or newJ >= c) continue;
        if (!visited[newI][newJ]) {
            if (graph[newI][newJ] == graph[i][j]) dfs(newI, newJ, compId);
        }
    }
}

void solve() {
    char ch;
    cin >> r >> c;
    graph.assign(r, vector<bool>(c, false));
    visited.assign(r, vector<bool>(c, false));
    component.assign(r, vector<int>(c, 0));
    
    f(i,0,r) f(j,0,c) {
        cin >> ch;
        graph[i][j] = ch == '1';
    }
    int compId = 0;
    f(i,0,r) f(j,0,c) {
        if (!visited[i][j]) dfs(i,j, compId++);
    }
    int k, x, y, x2, y2;
    cin >> k;
    f(i,0,k) {
        cin >> x >> y; x--; y--;
        cin >> x2 >> y2; x2--; y2--;
        if (component[x][y] == component[x2][y2]) {
            if (graph[x][y]) {
                cout << "decimal" << endl;
            } else {
                cout << "binary" << endl;
            }
        } else {
            cout << "neither" << endl;
        }
    }

}

int main() {
    optimize;
    solve();

    return 0;
}