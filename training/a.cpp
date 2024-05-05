#include "bits/stdc++.h"
using namespace std;
#define ll long long

bool check(vector<ll> &v, ll n, ll tam) {
    vector<ll> mod(3);
    ll numSockets = 0;
    for (ll i = 0; i < n; i++) {
        auto el = v[i];
        mod[el%3]++;
        numSockets += el / 3;
    }
    ll m = min(mod[1], mod[2]);
    mod[1] -= m;
    mod[2] -= m;
    numSockets += m;
    numSockets += mod[2];
    numSockets += mod[1] / 2;
    numSockets += mod[1] % 2;

    return (numSockets <= tam);
}

ll binarySearch(vector<ll> &v, ll l, ll r, ll tam) {
    ll res = 0;
    while (l <= r) {
        ll m = l + (r - l) / 2;

        if (check(v, m, tam)) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return res;
}

int main() {
    ll n, s;
    cin >> n >> s;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (s == 1 || n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (s == 2) {
        cout << min(n, (ll)2) << endl;
        return 0;
    }
    s -= 2;
    sort(v.begin(), v.end());
    v.pop_back();
    v.pop_back();

    cout << binarySearch(v,0,v.size(), s) + 2 << endl;


    return 0;
}