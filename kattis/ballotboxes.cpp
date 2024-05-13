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
    int n, b, a;
    while (cin >> n >> b) {
        if (n == -1 && b == -1) return;
        priority_queue<tuple<ld,int,int>> v;
        for (int i = 0; i < n; i++) {
            cin >> a;
            v.push({a, a, 1});
        }
        b -= n;
        while (b--) {
            auto [r, top, bottom] = v.top(); v.pop();
            v.push({((ld)(top))/((ld)(bottom+1)), top, bottom+1});
        }
        int m = 0;
        while (!v.empty()) {
            auto [r, top, bottom] = v.top(); v.pop();
            m = max(m, (top+bottom-1)/bottom);
        }
        cout << m << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}