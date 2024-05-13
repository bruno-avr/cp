#include "bits/stdc++.h"
using namespace std;

int main() {
    long double a, b, c, d;
    cin >> a >> b >> c >> d;
    long double res = (a * c - b * d) / (a-b);
    if (res > 100.000000005 or res <= -0.000000005) cout << "impossible" << endl;
    else cout << fixed << setprecision(10) << res << endl;

    return 0;
}