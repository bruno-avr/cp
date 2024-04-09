#include "bits/stdc++.h"

using namespace std;

int main()
{
    long long c, n, numLeft, numEntered, numStayed;
    long long totalInTrain = 0;;
    cin >> c >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> numLeft >> numEntered >> numStayed;
        totalInTrain -= numLeft;
        if (totalInTrain < 0) {
            cout << "impossible" << endl; return 0;
        }
        totalInTrain += numEntered;
        if (totalInTrain > c) {
            cout << "impossible" << endl; return 0;
        }
        if (numStayed > 0 && totalInTrain < c) {
            cout << "impossible" << endl; return 0;
        }
    }
    if (totalInTrain > 0) {
        cout << "impossible" << endl; return 0;
    }
    cout << "possible" << endl;

    return 0;
}
