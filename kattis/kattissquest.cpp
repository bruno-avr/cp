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
    ll n, e, g, x;
    string cmd;
    cin >> n;
    multiset<pair<ll, ll>> s;
    f(i,0,n) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> e >> g;
            s.insert({e, g});
        } else {
            ll total = 0;
            cin >> x;
            auto it = s.lower_bound({x+1, 0});
            while (s.size() && it != s.begin()) {
                it--;
                total += (*it).second;
                x -= (*it).first;
                s.erase(it);
                it = s.lower_bound({x+1, 0});
            }
            cout << total << endl;
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}