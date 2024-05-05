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
    vector<pair<int,int>> res;
    res.push_back({n,n});
    res.push_back({1,1});
    bool line = true;
    for(int i = 2; i < n; i++) {
        res.push_back({(line ? 1 : i), (line ? i : 1)});
        if (line) line = false;
    }
    set<int> see;
    for(auto el : res) {
        for(auto el2 : res) {
            see.insert(abs(el.first - el2.first) + abs(el.second - el2.second));
        }
    }
    for(auto el : res) {
        cout << el.first << " " << el.second << endl;
    }
    
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}