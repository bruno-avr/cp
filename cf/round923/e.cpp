#include "bits/stdc++.h"

#define ll long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> res(n);
    int currEl = 1, curr = 0, currIndex = 0;
    int currElBack = n;
    bool front = true;
    int totalEl = 1;
    while (totalEl <= n) {
        if (front) res[currIndex] = currEl++;
        else res[currIndex] = currElBack--;
        totalEl++;
        currIndex += k;
        if (currIndex >= n) {
            currIndex = ++curr;
            front = !front;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << res[i];
    }
    cout << endl;
    

    
}

int main() {
    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}