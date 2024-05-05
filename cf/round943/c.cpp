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

int func(vector<int> &res, vector<int> &v, int pos, int minimum) {
    if (pos == 0) {
        res[pos] = minimum+1;
        return minimum+1;
    }
    res[pos] = func(res, v, pos-1, v[pos-1]) + v[pos-1];
    while (res[pos] <= minimum) res[pos] += res[pos-1];
    return res[pos];
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> v[i];
    }
    vector<int> res(n);
    func(res, v, n-1, 0);
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << endl;
    
    
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}