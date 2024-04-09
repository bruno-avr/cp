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

bool kthBit(int n, int k) {
    return (n & ( 1 << k )) >> k;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    f(i,0,n) {
        cin >> v[i];
    }
    for (int i = 29; i >= 0; i--) {
        int numOn = 0, numOff = 0;
        f(j,0,n) {
            if (kthBit(v[j], i)) numOn++;
            else numOff++;
        }
        // cout << numOn << endl;
        if (kthBit(x, i)) {
            if (numOn % 2 != 0) continue;
            if (numOn == 0) {
                cout << numOff << endl;
            } else cout << numOn/2 << endl;
            return;

        } else if (numOn % 2 != 0) {
            cout << -1 << endl;
            return;
        } else if (i == 0) {
            cout << numOn/2 << endl;
        }
    }
    cout << -1 << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}