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
    ll n;
    cin >> n;

    set<ll> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.insert(i);
            res.insert(n / i);
        }
    }
    
    bool first = true;
    for (ll el : res) {
        if (first) first = false;
        else cout << " ";
        cout << el-1; 
    }
    cout << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}