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
    int n;
    cin >> n;
    int pos = 0, curr = 1;
    vector<int> res(n, -1);
    while (1) {
        f(i,0,curr) {
            do {
                pos = (pos + 1) % n;
            } while (res[pos] != -1);
        }
        res[pos] = curr++;
        if (curr > n) break;
        do {
            pos = (pos + 1) % n;
        } while (res[pos] != -1);
    }
    f(i,0,n) {
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