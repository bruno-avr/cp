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
    vector<pair<int,int>> vp(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        vp[i] = {a, -b};
    }
    sort(all(vp));
    vector<int> stacks;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(all(stacks), vp[i].second);
        if (it == stacks.end()) stacks.push_back(vp[i].second);
        else (*it) = vp[i].second;
    }
    cout << stacks.size() << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}