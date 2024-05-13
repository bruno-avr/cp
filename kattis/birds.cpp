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
    int l, d, n;
    cin >> l >> d >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    v.push_back(6-d);
    v.push_back(l-6+d);
    sort(all(v));
    int res = 0;
    for (int i = 1; i < v.size(); i++) {
        int diff = v[i] - v[i-1];
        res += diff/d-1;
    }
    cout << res << endl;
    
    
}

int main() {
    optimize;
    solve();

    return 0;
}