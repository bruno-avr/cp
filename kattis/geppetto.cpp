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
    int n, m, a, b;
    cin >> n >> m;
    int subs = (1<<n) - 1;
    set<pair<int,int>> v;
    f(i,0,m) {
        cin >> a >> b; a--; b--;
        v.insert({a,b});
    }
    int count = 1;
    for (int i = subs; i; i = (i-1)&subs) {
        bool possible = true;
        for (auto &el : v) {
            if (i & (1 << el.first))
                if (i & (1 << el.second)) {
                    possible = false;
                    break;
                }
        }
        if (possible) count++;
    }
    cout << count << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}