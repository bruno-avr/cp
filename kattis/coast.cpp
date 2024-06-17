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

int dr[] = { 0, 0, 1, -1 };            // the order is:
int dc[] = { 1, -1, 0, 0 };            // S/SE/E/NE/N/NW/W/SW

vector<vector<bool>> graph;
vector<vector<bool>> visited;
int r, c;
int res = 0;

int dfs(int i, int j) {
    if (i < 0 or i >= r) return 0;
    if (j < 0 or j >= c) return 0;
    if (graph[i][j]) return 1;
    if (visited[i][j]) return 0;
    visited[i][j] = true;
    int thisV = 0;
    for (int d = 0; d < 4; ++d) {
        int newI = i+dr[d], newJ = j+dc[d];
        thisV += dfs(newI, newJ);
    }
    return thisV;
}

void solve() {
    cin >> r >> c;
    graph.assign(r, vector<bool>(c, false));
    visited.assign(r, vector<bool>(c, false));
    
    char ch;
    f(i,0,r) f(j,0,c) {
        cin >> ch;
        graph[i][j] = ch == '1';
    }
    int res = 0;
    if (!graph[0][0]) res += dfs(0,0);
    if (!graph[0][c-1]) res += dfs(0,c-1);
    if (!graph[r-1][0]) res += dfs(r-1,0);
    if (!graph[r-1][c-1]) res += dfs(r-1,c-1);
    f(i,0,c) {
        if (graph[0][i]) res++;
        else res += dfs(0,i);
        if (graph[r-1][i]) res++;
        else res += dfs(r-1,i);
    }
    f(i,0,r) {
        if (graph[i][0]) res++;
        else res += dfs(i,0);
        if (graph[i][c-1]) res++;
        else res += dfs(i,c-1);
    }
    cout << res << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}