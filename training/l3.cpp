#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
#define all(x) x.begin(),x.end()
const long double INF = 1e18;

int main() {
    optimize;
    
    int n;
    cin >> n;

    string a, b;
    long double rate;

    unordered_map<string, long double> m;
    m["pink"] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> rate;
        if (m.count(a) == 0) m[a] = -INF;
        if (m.count(b) == 0) m[b] = -INF;
        m[a] = max(m[a], log2l(rate) + m[b]);
    }
    m["blue"] = min(m["blue"], (long double)10);

    cout << fixed << setprecision(10) << min((long double)10, powl(2, m["blue"])) << endl;

    return 0;
}