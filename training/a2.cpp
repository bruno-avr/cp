#include "bits/stdc++.h"
using namespace std;
#define ll long long

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
    ll cont = 2;
    ll totalW = s * 3;

    multiset<int> ms(v.begin(), v.end());

    while (ms.size()) {
        auto first = ms.begin();
        ms.erase(first);

        if (*first > totalW) break;
        cont++;

        if (*first % 3 == 0) continue;
        if (ms.size() == 0) break;

        auto second = ms.begin();

        int tam = *first + *second;
        while (tam % 3 != 0) tam++;
        
        if (tam  > totalW) {
            totalW -= *first;
            break;
        }
        totalW -= tam;
        cont++;
        
        int tamMax = tam - *first;
        auto pointer = ms.upper_bound(tamMax);
        pointer--;
        ms.erase(pointer);
    }
    cout << cont << endl;

    return 0;
}