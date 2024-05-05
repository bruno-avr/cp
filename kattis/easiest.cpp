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

ll getSum(ll n) {
    ll sum = 0;
    string s = to_string(n);
    for (auto &c : s) {
        sum += c-'0';
    }
    return sum;
}

void solve() {
    ll n;
    while (cin >> n, n) {
        ll sum = getSum(n);
        ll p = 11;
        while (true) {
            if (getSum(n*p) == sum) {
                cout << p << endl;
                break;
            }
            p++;
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}