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
    vector<int> maxV(n);
    vector<int> minV(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    maxV[0] = v[0];
    for (int i = 1; i < n; i++) {
        maxV[i] = max(maxV[i-1], v[i]);
    }
    minV[n-1] = v[n-1];
    for (int i = n-2; i >= 0; i--) {
        minV[i] = min(minV[i+1], v[i]);
    }
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (maxV[i] == minV[i]) cont++;
    }
    cout << cont << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}