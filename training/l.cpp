#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f

int main() {    
    int n;
    cin >> n;

    string a, b;
    double rate;

    unordered_map<string, double> m;
    m["pink"] = 0.0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> rate;
        if (m.count(a) == 0) m[a] = -INF;
        if (m.count(b) == 0) m[b] = -INF;
        m[a] = max(m[a], log(rate) + m[b]);
    }

    cout << fixed << setprecision(9) << min(10.0, exp(m["blue"])) << endl;

    return 0;
}