#include "bits/stdc++.h"

#define ll long long
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

void solve(int t) {
    int n, q, l, r;
    cin >> n;
    vector<int> v(n);
    vector<int> leftElIsDiff;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) {
        if (v[i] != v[i-1]) {
            leftElIsDiff.push_back(i+1);
        }
    }
    
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        auto it1 = lower_bound(leftElIsDiff.begin(), leftElIsDiff.end(), l+1);
        if (it1 != leftElIsDiff.end() && ((*(it1)) <= r)) {
            cout << *(it1)-1 << " " << (*(it1)) << "\n";
        } else {
            cout << -1 << " " << -1 << "\n";
        }
    }
    if (t != 0) cout << "\n";
    
}

int main() {
    optimize;
    int t;
    cin >> t;

    while (t--) solve(t);

    return 0;
}