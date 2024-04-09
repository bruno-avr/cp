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
    int n, a, b, p1, p2, res, totalA, totalB;
    vector<int> va(101, 0);
    vector<int> vb(101, 0);
    cin >> n;
    f(i,0,n) {
        cin >> a >> b;
        va[a]++;
        vb[b]++;
        totalA = 0;
        totalB = vb[100];
        p1 = 0;
        p2 = 100;
        res = 0;
        while (totalA <= i || totalB <= i) {
            if (totalB > totalA) {
                totalA += va[++p1];
            } else {
                totalB += vb[--p2];
            }
            if (va[p1] && vb[p2]) {
                res = max(res, p1+p2);
            }
        }
        cout << res << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}