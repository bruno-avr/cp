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
    ld t, a;
    int n;
    cin >> t >> n;

    // ratio (initialSize/numCuts), initialSize, numCuts
    multiset<tuple<ld, ld, ld>> pieces;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pieces.insert({a,a,1});
    }
    int numCuts = 0;

    // while ratio is not yet satisfied
    while(get<0>(*pieces.begin()) / get<0>(*pieces.rbegin())+0.000005 <= t) {
        auto maxN = *pieces.rbegin(); //get biggest element
        auto it = pieces.end(); it--; pieces.erase(it); //erase biggest element
        // insert element with new ratio
        pieces.insert({get<1>(maxN) / (get<2>(maxN)+1), get<1>(maxN), get<2>(maxN)+1});

        numCuts++;
    }
    cout << numCuts << endl;
    
}

int main() {
    optimize;
    solve();

    return 0;
}