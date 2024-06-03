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
    int r,s,k;
    cin>>r>>s>>k;
    vector<string> vs(r);
    f(i,0,r) cin >> vs[i];
    vector<vector<int>> v(r, vector<int>(s, 0));
    f(i,0,r)
        f(j,0,s) {
            v[i][j] = vs[i][j] == '*' ? 1 : 0;
            if (j > 0) v[i][j] += v[i][j-1];
        }

    k -= 2;
    int res = 0;
    int startL = 1, startC = 1;
    for (int i = 1; i < s-k; i++) {
        int j = i+k-1;
        int curr = 0;
        for (int l = 1; l <= k; l++) {
            curr += v[l][j] - v[l][i-1];
        }
        if (curr > res) {
            startL = 1;
            startC = i;
            res = curr;
        }
        int maxN = curr;
        for (int l = k+1; l < r-1; l++) {
            curr += v[l][j] - v[l][i-1];
            curr -= v[l-k][j] - v[l-k][i-1];
            if (curr > res) {
                startL = l-k+1;
                startC = i;
                res = curr;
            }
        }
    }
    for (int i = startL; i < startL+k; i++) vs[i][startC-1] = '|';
    for (int i = startL; i < startL+k; i++) vs[i][startC+k] = '|';
    for (int i = startC; i < startC+k; i++) vs[startL-1][i] = '-';
    for (int i = startC; i < startC+k; i++) vs[startL+k][i] = '-';
    vs[startL-1][startC-1] = vs[startL-1][startC+k] = vs[startL+k][startC-1] = vs[startL+k][startC+k] = '+';
    cout << res << endl;
    f(i,0,r) cout << vs[i] << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}