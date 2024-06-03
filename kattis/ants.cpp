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
    int l, n;
    cin >> l >> n;
    vector<int> v(n);
    int minDist = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        minDist = max(minDist, min(v[i], l-v[i]));
    }
    sort(all(v));
    int maxDist = max(v.back(), l-v[0]);
    cout << minDist << " " << maxDist << endl;
    
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}