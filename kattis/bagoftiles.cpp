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
int m;
int n, t;
int res1, res2;
vector<int> v;

int NCR(int n, int r)
{
    if (r == 0) return 1;
    if (r > n / 2) return NCR(n, n - r); 

    long res = 1; 

    for (int k = 1; k <= r; ++k)
    {
        res *= n - k + 1;
        res /= k;
    }

    return res;
}

int memo[30][10000][30];
int ways(int id, int sum, int cont) {
    if (cont == n) {
        if (sum == t) return 1;
        else return 0;
    }
    if (sum > t) return 0;
    if (id == m) return 0;

    int &res = memo[id][sum][cont];
    if (res != -1) return res;
    return res = ways(id+1, sum, cont) + ways(id+1, sum+v[id], cont+1);
}

void solve(int game) {
    memset(memo, -1, sizeof(memo));
    cin >> m;
    v.assign(m, 0);
    f(i,0,m) cin >> v[i];

    cin >> n >> t;

    res1 = ways(0,0,0);
    res2 = NCR(m, n) - res1;

    cout << "Game " << game << " -- " << res1 << " : " << res2 << endl;


    // int dp[n+1][t+1];
    // memset(dp, 0, sizeof(dp));

    // dp[0][0] = 1;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= t; j++) {
    //         if (dp[i-1][j] != 0) {
    //             for (int k = 0; k < n; k++) {
    //                 if (j+v[k] <= t)
    //                     dp[i][j+v[k]] += dp[i-1][j];
    //             }
    //         }
    //     }
    // }

    // cout << "Game " << game << " -- " << dp[n][t] << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;
    int game = 1;

    while (T--) solve(game++);

    return 0;
}