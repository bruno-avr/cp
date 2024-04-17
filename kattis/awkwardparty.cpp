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
    unordered_map<int, int> um;
    int minN = n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (um.find(a) != um.end()) {
            minN = min(minN, i - um[a]);
        }
        um[a] = i;
    }
    
    cout << minN << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}