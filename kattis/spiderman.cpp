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

int n;
int memo[41][1010];
int v[41];

int dp(int i, int height) {
    if (height < 0 or height >= 1010) return 1010;
    if (i == n) {
        if (height == 0) return 0;
        return 1010;
    }
    int &res = memo[i][height];
    if (res != -1) return res;

    return res = min(
        max(height+v[i], dp(i+1, height+v[i])),
        max(height, dp(i+1, height-v[i]))
    );
}

void print(int i, int height) {
    if (i == n) return;
    int &res = memo[i][height];

    if (max(height+v[i], dp(i+1, height+v[i])) == memo[i][height]) {
        cout << "U";
        print(i+1, height+v[i]);
    } else {
        cout << "D";
        print(i+1, height-v[i]);
    }
}

void solve() {
    memset(memo, -1, sizeof memo);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    int res = dp(0, 0);
    // cout << res << endl;
    if (res >= 1010) cout << "IMPOSSIBLE" << endl;
    else {
        print(0,0);
        cout << endl;
    }
}

int main() {
    optimize;
    int T; cin >> T;
    while (T--) solve();

    return 0;
}