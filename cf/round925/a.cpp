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
    n -= 3;
    int v[3];
    v[0] = v[1] = v[2] = 1;
    int curr = 2;
    while (n > 0) {
        int a = min(25, n);;
        v[curr] += min(25, a);
        n -= a;
        curr--;
    }
    f(i, 0, 3) {
        char c = 'a'+v[i]-1;
        cout << c;
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