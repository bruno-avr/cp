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

double d, s;

double p(double a) {
    return cosh(d/(2*a)) * a - (a+s);
}

double bs() {
    double l = 0, r = 1e9;
    f(i,0,100) {
        double m = (l+r)/2;
        (p(m) > 0) ? l = m : r = m;
    }
    return l;
}

void solve() {
    cin >> d >> s;
    double a = bs();
    double res = 2*a*sinh(d/(2*a));
    cout << fixed << setprecision(10) << res << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}