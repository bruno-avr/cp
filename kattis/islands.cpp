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
    ll n = 12, k;
    cin >> k;
    cout << k << " ";
    vector<ll> v(n);
    f(i,0,n) {
        cin >> v[i];
    }
    int cont = 0;
    f(i,1,n-1) {
        f(j,i,n-1) {
            ll smallest = 1e18;
            f(k, i, j+1) {
                smallest = min(smallest, v[k]);
            }
            if (smallest > v[i-1] && (smallest > v[j+1])) {
                cont++;
            }
        }
    }
    cout << cont << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}