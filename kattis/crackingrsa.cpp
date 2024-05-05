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
    ll n, e;
    cin >> n >> e;
    ll p = -1, q;
    for (ll i = 2; i < n; i++) {
        if (n%i == 0) {
            if (p == -1) p = i;
            else q = i;
        }
    }
    ll funcE = (p-1)*(q-1);
    for (ll d = 2; d < funcE; d++) {
        if ((d*e-1) % funcE == 0) {
            cout << d << endl;
            return;
        }
    }
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}