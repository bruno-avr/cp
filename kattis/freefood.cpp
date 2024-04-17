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
    int n, a, b;
    cin >> n;
    vector<int> v(365, false);
    for (int i = 0; i < n; i++) {
        cin >> a >> b; a--; b--;
        for (int j = a; j <= b; j++) {
            v[j] = true;
        }
    }
    int cont = 0;
    for (int i = 0; i < 365; i++) {
        if (v[i]) cont++;
    }
    cout << cont << endl;
    
    
}

int main() {
    optimize;
    solve();

    return 0;
}