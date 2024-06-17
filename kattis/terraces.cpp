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

int graph[501][501];
bool visited[501][501];
int x, y;
int res;
int xs[] = {0, 0, 1, -1};
int ys[] = {-1, 1, 0, 0};

void dfs(int a, int b, int val) {
    if (graph[a][b] == val) res++;
    visited[a][b] = true;
    for (int i = 0; i < 4; i++) {
        if (a + xs[i] < 0) continue;
        if (b + ys[i] < 0) continue;
        if (a + xs[i] >= x) continue;
        if (b + ys[i] >= y) continue;
        if (graph[a + xs[i]][b + ys[i]] >= graph[a][b]) {
            if (!visited[a + xs[i]][b + ys[i]]) {
                dfs(a + xs[i], b + ys[i], val);
            }
        }
    }
}

void solve() {
    res = 0;
    cin >> y >> x;
    vector<pair<int, pair<int,int>>> v;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> graph[i][j], v.push_back({graph[i][j], {i, j}});
    sort(all(v));
    for (int i = 0; i < (int)v.size(); i++) {
        if (!visited[v[i].second.first][v[i].second.second]) {
            dfs(v[i].second.first,v[i].second.second, v[i].first);
        }
    }
    cout << res << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}