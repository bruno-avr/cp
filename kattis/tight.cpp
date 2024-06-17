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

ll n, k;
ld memo[101][11];

ld ways(ll id, ll prev) {
    if (id == n) return 1;
    ld &res = memo[id][prev];
    if (res != -1) return res;
    res = 0;
    for (ll i = max(prev-1, (ll)0); i <= min(prev+1, k); i++) {
        res += ways(id+1, i);
    }
    return res;
}

void solve() {
    // memset(memo, -1, sizeof memo);
    for (int i = 0; i < 101; i++) {
        f(j,0,11) memo[i][j] = -1;
    }
    ld res = 0;
    for (ll i = 0; i <= k; i++) {
        res += ways(1, i);
    }
    ld totalWays = 1;
    f(i,0,n) totalWays *= (k+1);
    res /= totalWays;
    res *= 100;
    cout << fixed << setprecision(10) << res << endl;
}

int main() {
    optimize;
    while (cin >> k >> n) solve();

    return 0;
}