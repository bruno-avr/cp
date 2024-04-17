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
    int r, n, c;
    cin >> r >> n;
    vector<bool> v(r);
    f(i,0,n) {
        cin >> c; c--;
        v[c] = true;
    }
    int cont = 0;
    f(i,0,r) {
        if (!v[i]) {
            cout << i+1 << endl;
            return;
        }
    }
    cout << "too late" << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}