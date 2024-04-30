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
    vector<int> v(n);
    vector<int> v2(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
    }
    sort(all(v2));
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > v2[i]) {
            v.push_back(v2[i]);
            sort(all(v));
            cont++;
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