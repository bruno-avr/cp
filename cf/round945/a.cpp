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
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 2) {
        cout << -1 << endl;
        return;
    }
    int res = 0;
    while (b > a) {
        res += 1;
        b--;
        c--;
    }
    while (a) {
        if (c > 0) {
            if (c > 1) {
                a--;
                b--;
                c-= 2;
                res+= 2;
            } else {
                a--;
                c--;
                res++;
            }
        } else {
            a--;
            b--;
            res++;
        }
    }

    cout << res << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}