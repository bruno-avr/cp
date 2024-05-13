#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll unsigned long long

int main() {
    optimize;
    ll n, q, a;
    cin >> n >> q;
    vector<tuple<ll,ll,ll>> v(n);
    for (ll i = 1; i <= n; i++) {
        cin >> a;
        v[i-1] = {i, a, i-1};
    }
    vector<tuple<ll,ll,ll>> ordered(v);
    tuple<ll,ll,ll> minT = v[0];
    for (ll i = 1; i < n; i++) {
        auto &[x1,y1,i1] = minT;
        auto &[x2,y2,i2] = v[i];
        ll aux = lcm(y1, y2);
        ll first = aux/y1 * x1;
        ll second = aux/y2 * x2;
        if (first < second) minT = v[i];
    }
    // sort(ordered.begin(), ordered.end(), [](const tuple<ll,ll,ll> &e1, const tuple<ll,ll,ll> &e2){
    //     auto &[x1,y1,i1] = e1;
    //     auto &[x2,y2,i2] = e2;
    //     ll aux = lcm(y1, y2);
    //     ll first = aux/y1 * x1;
    //     ll second = aux/y2 * x2;
    //     cout <<first << endl;
    //     cout << second << endl;
    //     if (first == second) return true;
    //     if (first > second) return true;
    //     return false;
    // });
    auto &[x1,y1,i1] = minT;
    // cout << x1 << " " << y1 << " " << i1 << endl;
    vector<ll> aux(3*n, 987654321987654321);
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            // cout << "i" << i << " " << "j" << j << " " <<get<1>(v[i-1]) + get<1>(v[j-1]) <<  endl;
            aux[i+j] = min(get<1>(v[i-1]) + get<1>(v[j-1]), aux[i+j]);
        }
    }
    while (q--) {
        ll k;
        cin >> k;
        if (k <= n) {
            auto &[x2,y2,i2] = v[k-1];
            cout << y2 << endl;
            continue;
        }
        ll res = 987654321987654321;
        
        for (ll ij = n+1; ij <= min(k, 2*n); ij++) {
            if ((k-(ij))%x1 == 0) {
                ll thisV = (k-(ij))/x1;
                thisV *= y1;
                thisV += aux[ij];
                res = min(res, thisV);
                // cout << k << " " << ij << " " << aux[ij] << endl;
            }
        }
        cout << res << endl;
    }

    return 0;
}