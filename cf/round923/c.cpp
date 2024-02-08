#include "bits/stdc++.h"

#define ll long long

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v1(n);
    vector<int> v2(m);
    set<int> s1;
    set<int> s2;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
        s1.insert(v1[i]);
    };
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
        s2.insert(v2[i]);
    };


    bool possible = true;
    int unique1 = 0;
    int unique2 = 0;
    for (int i = 1; i <= k; i++) {
        bool foundIn1 = s1.find(i) != s1.end();
        bool foundIn2 = s2.find(i) != s2.end();
        if (!foundIn1 && !foundIn2) {
            possible = false;
            break;
        }
        else if (foundIn1 && !foundIn2) unique1++;
        else if (foundIn2 && !foundIn1) unique2++;
    }
    
    if (unique1 > k/2) possible = false;
    if (unique2 > k/2) possible = false;

    if (possible) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}

int main() {
    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}