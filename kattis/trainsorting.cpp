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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    reverse(all(v));
    vector<int> stacks1;
    vector<int> stacks2;
    int res = 0;
    for (int i = 0; i < n; i++) {
        auto it1 = lower_bound(all(stacks1), v[i]);
        auto it2 = lower_bound(all(stacks2), -1*v[i]);

        res = max(res, (int)(it1 - stacks1.begin()) + (int)(it2 - stacks2.begin())+1);

        if (it1 == stacks1.end()) stacks1.push_back(v[i]);
        else (*it1) = v[i];

        if (it2 == stacks2.end()) stacks2.push_back(-1*v[i]);
        else (*it2) = -1*v[i];

    }
    cout << res << endl;
    // reverse(all(v));
    // vector<int> dp1(n);
    // vector<int> dp2(n);
    // for (int i = 0; i < n; i++) {
    //     dp1[i] = 1;
    //     for (int j = i-1; j >= 0; j--) {
    //         if (v[j] < v[i]) dp1[i] = max(dp1[i], dp1[j]+1);
    //     }
    // }
    // for (int i = 0; i < n; i++) {
    //     dp2[i] = 1;
    //     for (int j = i-1; j >= 0; j--) {
    //         if (v[j] > v[i]) dp2[i] = max(dp2[i], dp2[j]+1);
    //     }
    // }
    // int res = 0;
    // for (int i = 0; i < n; i++) {
    //     res = max(res, dp1[i]+dp2[i]-1);
    // }
    // cout << res << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}