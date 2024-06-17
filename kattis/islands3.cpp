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
vector<vector<char>> graph;
vector<vector<bool>> visited;
int r, c;

int dr[] = { 0, 0, 1, -1 };            // the order is:
int dc[] = { 1, -1, 0, 0 };            // S/SE/E/NE/N/NW/W/SW

void dfs(int i, int j) {
    visited[i][j] = true;
    graph[i][j] = 'L';
    for (int d = 0; d < 4; ++d) {
        int newI = i+dr[d], newJ = j+dc[d];
        if (newI < 0 or newI >= r) continue;
        if (newJ < 0 or newJ >= c) continue;
        if (!visited[newI][newJ]) {
            if (graph[newI][newJ] == 'C' or graph[newI][newJ] == 'L') dfs(newI, newJ);
        }
    }
}

void solve() {
    cin >> r >> c;
    graph.assign(r, vector<char>(c));
    visited.assign(r, vector<bool>(c, false));
    
    f(i,0,r) f(j,0,c) {
        cin >> graph[i][j];
    }
    
    int res = 0;
    f(i,0,r) f(j,0,c) {
        if (graph[i][j] == 'L' && !visited[i][j]) {
            dfs(i,j);
            res++;
        }
    }
    cout << res << endl;

}

int main() {
    optimize;
    solve();

    return 0;
}