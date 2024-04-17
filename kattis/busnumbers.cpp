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
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sort(all(v));
    cout << v[0];
    int last = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i-1]+1) {
            if (i+1 == n or v[i] != v[i+1]-1) {
                if (last == v[i-1]) cout << " " << v[i];
                else cout << "-" << v[i];
            }
        } else {
            cout << " " << v[i];
            last = v[i];
        }
    }
    cout << endl;;
}

int main() {
    optimize;
    solve();

    return 0;
}