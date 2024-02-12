#include "bits/stdc++.h"

#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> diffs;
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++) {
        if (v[i] - v[i-1] > 0) {
            diffs.push_back(v[i] - v[i-1]);
        }
    }

    int p1 = 0;
    int sum = 0;
    int totalPoints = 1;
    int maxPoints = 1;

    for (int i = 0; i < diffs.size(); i++) {
        sum += diffs[i];
        totalPoints++;
        if (sum < n) {
            maxPoints = max(maxPoints, totalPoints);
        }
        while (sum >= n) {
            sum -= diffs[p1++];
            totalPoints--;
        }
    }
    
    cout << maxPoints << endl;

}

int main() {
    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}