#include "bits/stdc++.h"

#define ll long long

using namespace std;

unordered_set<ll> res;

void insertK(ll n, ll x) {
    if (n % 2 != 0) return;
    ll k = n/2+1;
    if (k >= x) res.insert(k);
}

void calc (ll n, ll x) {
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            insertK(n/i, x);
            insertK(n/(n/i), x);
        }
    }
}

void solve() {
    res.clear();
    ll n, x;
    cin >> n >> x;
    
    // case 1
    ll a = n - x;
    calc(a, x);

    // case 2
    ll b = n + x - 2;
    calc(b, x);

    cout << res.size() << endl;

}

int main() {
    ll t;
    cin >> t;

    while (t--) solve();

    return 0;
}