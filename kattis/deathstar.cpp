#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    vector<int> res(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            res[i] |= v[i][j];
            res[j] |= v[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << res[i] << ((i == n-1) ? "\n" : " ");
    }
    
    return 0;
}