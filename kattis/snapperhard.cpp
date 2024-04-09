#include "bits/stdc++.h"

using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        cin >> n >> k;
        
        cout << "Case #" << i << ": ";
        
        int mask = (1<<n)-1;
        if ((mask & k) == mask) cout << "ON";
        else cout << "OFF";
        
        cout << endl;
    }
    
    return 0;
}