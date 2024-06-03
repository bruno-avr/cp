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
    int n, t;
    cin >> n >> t;
    int cash, time;
    vector<pair<int, int>> v(n);
    vector<bool> schedule(t, 0);
    for (int i = 0; i < n; i++) {
        cin >> cash >> time;
        v[i] = {-cash, time};
    }
    sort(all(v));
    int res = 0;
    for (auto &el : v) {
        cash = -el.first;
        time = el.second;
        for (int i = time; i >= 0; i--) {
            if (!schedule[i]) {
                schedule[i] = true;
                res += cash;
                break;
            }
        }
    }
    cout << res << endl;

}

int main() {
    optimize;
    solve();

    return 0;
}