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

int n, k;
int anglesKnown[11];
int anglesAsked[11];
int angles[360];

void dp(int angle) {
    int &res = angles[angle];
    if (res != -1) return;
    res = 1;
    f(i,0,n) {
        dp((angle-anglesKnown[i]+360)%360);
        dp((angle+anglesKnown[i]+360)%360);
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> anglesKnown[i];
    for (int i = 0; i < k; i++) cin >> anglesAsked[i];
    memset(angles, -1, sizeof angles);
    dp(0);
    for (int i = 0; i < k; i++) cout << ((angles[anglesAsked[i]] == 1) ? "YES" : "NO") << endl;

}

int main() {
    optimize;
    solve();

    return 0;
}