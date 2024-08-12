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

int p1, p2;
void solve() {
    vector<vector<bool>> visited(2001, vector<bool>(2001, false));
    int a, s;
    queue<tuple<int,int,int>> q;
    for (int i = 0; i < p1; i++) {
        cin >> a >> s;
        visited[a][s] = 1;
        q.push({a,s,0});
    }
    cin >> p2;
    set<pair<int,int>> s2;
    for (int i = 0; i < p2; i++) {
        cin >> a >> s;
        s2.insert({a,s});
    }

    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    while(!q.empty()) {
        auto el = q.front(); q.pop();
        f(i,0,4) {
            int x = get<0>(el) + dx[i];
            int y = get<1>(el) + dy[i];
            int dist = get<2>(el);
            if (x < 0 or y < 0 or x > 2000 or y > 2000) continue;
            if (!visited[x][y]) {
                visited[x][y] = 1;
                q.push({x,y,dist+1});
                if (s2.count({x,y})) {
                    cout << dist+1 << endl;
                    return;
                }
            }
        }
    }
}

int main() {
    optimize;

    while (1) {
        cin >> p1;
        if (p1 == 0) break;
        solve();
    }

    return 0;
}