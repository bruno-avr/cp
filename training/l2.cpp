#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
#define all(x) x.begin(),x.end()

int main() {
    optimize;
    
    int n;
    cin >> n;

    string a, b;
    long double rate;

    unordered_map<string, long double> m;
    m["pink"] = 1.0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> rate;
        m[a] = max(m[a], rate * m[b]);
    }

    cout << fixed << setprecision(10) << min((long double)10, m["blue"]) << endl;

    return 0;
}