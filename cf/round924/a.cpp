#include "bits/stdc++.h"

#define ll long long

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b;
    if (b > a) swap(a, b);

    bool try1 = false;
    if (a % 2 == 0) {
        c = a/2;
        d = 2*b;
        if (d > c) swap(c, d);
        if (a != c || b != d) try1 = true;
    }

    if (b % 2 == 0) {
        c = 2*a;
        d = b/2;
        if (d > c) swap(c, d);
        if (a != c || b != d) try1 = true;
    }

    
    if (try1) cout << "Yes" << endl;
    else cout << "No" << endl;

}

int main() {
    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}