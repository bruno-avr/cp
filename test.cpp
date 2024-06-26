// Online C++ compiler to run C++ program online
#include "bits/stdc++.h"

using namespace std;

#define ld long double

ld it = 100, cr = 0.999;
int ni = 100000;

int calculate(vector<int> &v) {
    int sum = 0;
    for(int i = 1; i < v.size(); i++) sum += abs(v[i] - v[i-1]);
    return sum;
}

int simulatedAnnealing(vector<int> &best) {
    ld t = it;
    vector<int> curr(best);
    int bestVal, currVal;
    bestVal = currVal = calculate(curr);

    for (int i = 0; i < ni; i++) {
        int r1 = rand()%curr.size();
        int r2 = rand()%curr.size();
        swap(curr[r1], curr[r2]);

        int newVal = calculate(curr);
        int d = currVal - newVal;

        if (d <= 0 || (rand() / static_cast<ld>(RAND_MAX)) < exp(-d / t)) {
            currVal = newVal;
            if (currVal > bestVal) {
                best = curr;
                bestVal = currVal;
            }
        } else swap(curr[r1], curr[r2]);
        
        t *= cr;
    }
    
    return bestVal;
}

void solve(int c) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int res = simulatedAnnealing(v);
    cout << "Case " << c << ": " << res << endl;
}

int main() {
    srand(time(0));
    int t; cin >> t;
    int c = 1;
    while(t--) solve(c++);
    return 0;
}