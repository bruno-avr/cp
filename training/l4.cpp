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
    unordered_map<string, string> father;
    unordered_map<string, long double> rating;
    m["pink"] = 1.0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> rate;
        if (a == b) continue;
        if (rate * m[b] > m[a]) {
            m[a] = rate * m[b];
            father[a] = b;
            rating[a] = rate;
        }
    }
    if (!m["blue"]) {
        cout << fixed << setprecision(10) << 0.0 << endl;
        return 0;
    }
    deque<long double> d;
    string curr = "blue";
    while(curr != "pink") {
        d.push_back(rating[curr]);
        curr = father[curr];
    }
    sort(all(d));
    long double res = 1;
    while(d.size()) {
        res *= d.front();
        d.pop_front();
        if (!d.size()) break;
        res *= d.back();
        d.pop_back();
        if (res > 10000000000) break;
        if (res < 0.00000000001) break;
    }

    cout << fixed << setprecision(10) << min((long double)10, m["blue"]) << endl;

    return 0;
}