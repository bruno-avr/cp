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

int func(char c) {
    if (c == '<') return -1;
    return 1;
}

void dfs(vector<vector<int>> &v, vector<bool> &visited, int pos) {
    visited[pos] = true;
    for (auto viz : v[pos]) {
        if (!visited[viz]) {
            dfs(v, visited, viz);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    vector<vector<int>> v(2*n);
    vector<bool> visited(2*n, false);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                v[j].push_back(n+j+func(s[1][j]));
            } else {
                v[n+j].push_back(j+func(s[0][j]));
            }
            if (j > 0) {
                if (i == 0) {
                    v[j].push_back(j-1+func(s[i][j-1]));
                } else {
                    v[n+j].push_back(n+j-1+func(s[i][j-1]));
                }
            }
            if (j != n-1) {
                if (i == 0) {
                    v[j].push_back(j+1+func(s[i][j+1]));
                } else {
                    v[n+j].push_back(n+j+1+func(s[i][j+1]));
                }
            }
        }
    }
    v[n-1].push_back(2*n-1);
    v[2*n-2].push_back(2*n-1);
    // for (int i = 0; i < v.size(); i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < v[i].size(); j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    dfs(v, visited, 0);
    // for (int i = 0; i < visited.size(); i++) {
    //     cout << visited[i] << " ";
    // }
    if (visited[2*n-1]) yes();
    else no();
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}