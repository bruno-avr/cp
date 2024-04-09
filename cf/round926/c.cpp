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
    int k, x, a;
    cin >> k >> x >> a;
    
    unsigned long long totalLost = 0, currBet;
    f(i, 0, x+1) {
        currBet = totalLost + 1;
        currBet /= (k-1);
        if ((totalLost + 1) % ((k-1)) != 0) {
            currBet++;
        }

        totalLost += currBet;
        // cout << totalLost << endl;
    }
    if (totalLost <= a) yes();
    else no();
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}