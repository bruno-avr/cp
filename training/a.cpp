#include "bits/stdc++.h"
 
using namespace std;
 
int main() {
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        reverse(v.begin(), v.end());
 
        int maxR = 1;
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            int aux = 0;
            if (s.count(v[i])) aux++;
            s.insert(v[i]);
            s.erase(n-i);
            maxR = max(maxR, (int)s.size() + aux);
        }
 
        cout << maxR << endl;
    }
    
    
    return 0;
}