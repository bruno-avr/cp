#include "bits/stdc++.h"

#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> uses(26);

    string c = "a";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if(uses[j] == v[i]) {
                uses[j]++;
                c[0] = 'a' + j;
                cout << c;
                break;
            }
        }
    }
    cout << endl;


}

int main() {
    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}