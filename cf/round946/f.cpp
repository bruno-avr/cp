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

void solve() {
    int a, b, n, m, x, y;
    cin >> a >> b >> n >> m;
    set<pair<int,int>> lines, rlines;
    set<pair<int,int>> columns, rcolumns;
    map<pair<int,int>, bool> visited;
    f(i,0,n) {
        cin >> x >> y;
        lines.insert({x, y});
        rlines.insert({-x, y});
        columns.insert({y, x});
        rcolumns.insert({-y, x});
    }

    int res[] = {0,0};
    int curr = 0;
    string type;
    int qnt;
    int startL = 1, endL = a;
    int startC = 1, endC = b;
    f(i,0,m) {
        cin >> type >> qnt;
        if (type == "U") {
            while(1) {
                auto k = rlines.lower_bound({-(startL+qnt-1),0});
                if (k == rlines.end()) break;
                rlines.erase(k);
                pair<int, int> p = {-1*(*k).first, (*k).second};
                if (visited[p]) continue;
                visited[p] = true;
                res[curr]++;
            }
            startL += qnt;
        }
        if (type == "D") {
            while(1) {
                auto k = lines.lower_bound({(endL-qnt+1),0});
                if (k == lines.end()) break;
                lines.erase(k);
                pair<int, int> p = {(*k).first, (*k).second};
                if (visited[p]) continue;
                visited[p] = true;
                res[curr]++;
            }
            endL -= qnt;
        }
        if (type == "L") {
            while(1) {
                auto k = rcolumns.lower_bound({-(startC+qnt-1),0});
                if (k == rcolumns.end()) break;
                rcolumns.erase(k);
                pair<int, int> p = {(*k).second, -1*(*k).first};
                if (visited[p]) continue;
                visited[p] = true;
                res[curr]++;
            }
            startC += qnt;
        }
        if (type == "R") {
            while(1) {
                auto k = columns.lower_bound({(endC-qnt+1),0});
                if (k == columns.end()) break;
                columns.erase(k);
                pair<int, int> p = {(*k).second, (*k).first};
                if (visited[p]) continue;
                visited[p] = true;
                res[curr]++;
            }
            endC -= qnt;
        }

        curr = 1-curr;
    }
    cout << res[0] << " " << res[1] << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}