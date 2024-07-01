#include "bits/stdc++.h"

using namespace std;

void solve() {
    int res = 0;
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    for (int i = l1; i <= r1; i++) {
        int a = i;
        for (int j = l2; j <= r2; j++) {
            int b = j;
            int curr = a+b;
            while (curr) {
                res = max(res, curr%10);
                if (res == 9) {
                    cout << res << endl;
                    return;
                }
                curr /= 10;
            }
        }
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}