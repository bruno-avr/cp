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

int dp[2000010];
int memo[2000010];
int dp2(vector<int> &v2, int id) {
    if (id <= 0) return 0;
    auto &res = memo[id];
    if (res != -1) return res;
    auto it = lower_bound(all(v2), -id);
    return res = dp2(v2, id + (*it)) + 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> v2(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v2[i] = -v[i];
    }
    reverse(all(v2));

    memset(dp, -1, sizeof(dp));
    memset(memo, -1, sizeof(memo));
    dp[0] = 0;
    for (int i = 1; i < 2000010; i++) {
        dp[i] = dp[i-v[0]]+1;
        for (int j = 1; j < n; j++) {
            if (i-v[j] >= 0) {
                dp[i] = min(dp[i], dp[i-v[j]]+1);
            }
        }
    }
    // dp2(v2, 2000010-1);
    for (int i = 1; i < 2000010; i++) {
        if (dp[i] != -1) {
            if (dp2(v2, i) != dp[i]) {
                cout << "non-canonical" << endl;
                return;
            }
        }
    }
    cout << "canonical" << endl;
    // reverse(all(v2));
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         int sum = v[i]+v[j], cont = 0;
    //         while (sum != 0) {
    //             auto it = lower_bound(all(v2), -sum);
    //             sum += *it;
    //             cont++;
    //         }
    //         if (cont > 2) {
    //             cout << "non-canonical" << endl;
    //             return;
    //         }
    //     }
    // }
    // cout << "canonical" << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}