#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        for (int i = 29; i >= 0; i--) {
            if (a&(1<<(i+1))) a^=(1<<(i));
        }
        cout << a << endl;
    }
    return 0;
}