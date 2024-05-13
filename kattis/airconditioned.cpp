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
    int n, a, b;
    cin >> n;
    vector<pair<int,int>> v(n);
    pair<int,int> curr = {0, 1000};
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(all(v));
    int res = 1;
    for (int i = 0; i < n; i++) {
        if ((v[i].first >= curr.first && v[i].first <= curr.second)
            or (v[i].second >= curr.first && v[i].second <= curr.second)) {
            curr.first = max(curr.first, v[i].first);
            curr.second = min(curr.second, v[i].second);
        } else {
            curr = v[i];
            res++;
        }
    }
    cout << res << endl;
    
}

int main() {
    optimize;
    solve();

    return 0;
}