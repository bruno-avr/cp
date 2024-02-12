#include "bits/stdc++.h"

#define ll long long

using namespace std;

int numRestaurants = 0;
int maxNum;
vector<bool> visited(500000, false);

void dfs(vector<vector<int>> &v, vector<bool> &hasCat, int x, int numConsecutiveCats) {
    visited[x] = true;

    if (numConsecutiveCats > maxNum) return;

    if (v[x].size() == 1 && x != 0) {
        numRestaurants++;
        return;
    }
    for (auto viz : v[x]) {
        if (!visited[viz]) {
            dfs(v, hasCat, viz, hasCat[viz] ? (numConsecutiveCats+1) : 0);
        }
    }
}

int main() {
    int n, a, b;
    cin >> n >> maxNum;

    vector<bool> hasCat(n);

    for (int i = 0; i < n; i++) {
        cin >> a;
        hasCat[i] = (a == 1);
    }

    vector<vector<int>> v(n);

    for (int i = 0; i < n-1; i++) {
        cin >> a >> b; a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(v, hasCat, 0, (int)hasCat[0]);

    cout << numRestaurants << endl;

    return 0;
}