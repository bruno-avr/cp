#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

int main() {
    ll d, h;
    vector<string> v(7);
    for(int i = 0; i < 7; i++) {
        cin >> v[i];
    }
    cin >> d >> h;

    vector<int> perm(7);
    iota(all(perm), 0);
    // set<vector<int>> visited;
    int maxTotal = 0;
    do {
        vector<int> thisPerm(perm.begin(), perm.begin()+d);
        // if (visited.count(thisPerm)) continue;
        vector<int> cont(24);
        for(int i = 0; i < d; i++) {
            for(int j = 0; j < 24; j++) {
                if (v[perm[i]][j] == '.') cont[j]++;
            }
        }
        sort(all(cont));
        reverse(all(cont));
        int thisTotal = 0;
        for(int i = 0; i < h; i++) {
            thisTotal += cont[i];
        }
        maxTotal = max(maxTotal, thisTotal);
    } while (next_permutation(all(perm)));

    cout << fixed << setprecision(10) << (long double)maxTotal / ((long double)d * (long double)h) << endl;


    return 0;
}