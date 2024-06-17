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

int n;
int v[1010];
bool memo[1010][2010];

void dp(int id, int currW) {
    if (currW < 0 or currW >= 2010) return;
    bool &res = memo[id][currW];
    if (res) return;
    memo[id][currW] = true;
    if (id == n) return;

    memo[id][currW] = true;
    dp(id+1, currW);
    dp(id+1, currW+v[id]);
}

void solve() {
    memset(memo, 0, sizeof memo);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    dp(0, 0);
    for (int i = 0; i < 1000; i++) {
        if (memo[n][1000+i]) {
            cout << 1000+i << endl;
            return;
        }
        if (memo[n][1000-i]) {
            cout << 1000-i << endl;
            return;
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}