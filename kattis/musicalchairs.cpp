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
    int n, a;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        v[i] = {a, i+1};
    }
    int pos = 0;
    for (int i = 0; i < n-1; i++) {
        int thisN = n-i;
        int k = (v[pos].first-1)%thisN;
        pos = (pos + k)%thisN;
        v.erase(v.begin()+pos);
        pos %= thisN-1;
    }
    cout << v[0].second << endl;
    
}

int main() {
    optimize;
    solve();

    return 0;
}