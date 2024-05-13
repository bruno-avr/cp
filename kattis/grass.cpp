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

const ld eps = 0.00000005;

void solve(int n) {
    ld l, h, x, r;
    cin >> l >> h;
    h /= 2.0;
    vector<pair<ld,ld>> v;
    f(i,0,n) {
        cin >> x >> r;
        ld d = sqrt(r*r-h*h);
        if (r > h+eps) v.push_back({x-d, x+d});
    }
    sort(all(v));
    ld covered = 0;
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ld maxR = -1;
        int j;
        for (j = i; j < v.size(); j++) {
            if (v[j].first >= covered+eps) break;
            if (v[j].second > maxR) {
                maxR = v[j].second;
            }
        }
        ans++;
        i = j-1;
        if (maxR == -1) {
            cout << -1 << endl;
            return;
        }
        covered = maxR;
        if (covered + eps > l) {
            cout << ans << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    optimize;
    int n;
    while (cin >> n) solve(n);

    return 0;
}