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

#define f(i,s,e) for(ll i=s;i<e;i++)
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

void solve() {
    ll n, k, mod = 1000000000+7;
    cin >> n >> k;
    vector<ll> v(n);
    ll totalSum = 0;
    f(i,0,n) {
        cin >> v[i];
        totalSum += v[i];
    }
    ll currMax = 0;
    ll maxEnd = 0;
    ll currSum = 0;
    f(i,0,n) {
        currSum += v[i];
        if (currSum < 0) {
            currSum = 0;
        } else if (currSum > currMax) {
            currMax = currSum;
            maxEnd = i;
        }
    }
    f(i,0,k) {
        totalSum = (totalSum + mod + currMax) % mod;
        currMax = (currMax * 2) % mod;
    }
    cout << totalSum% mod << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}