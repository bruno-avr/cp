#include "bits/stdc++.h"

#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int firstBlack = -1;
    int lastBlack = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            firstBlack = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == 'B') {
            lastBlack = i;
            break;
        }
    }
    cout << lastBlack - firstBlack + 1 << endl;

}

int main() {
    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}