#include "bits/stdc++.h"

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ld long double
#define INF 0x3f3f3f3f

using namespace std;

void print(vector<vector<char>> &g) {
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[0].size(); j++)
            cout << g[i][j];
        cout << endl;
    }
}

bool check(vector<vector<char>> &g) {
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[0].size(); j++)
            if (g[i][j] == '.') return false;
    }
    return true;
}

void expand(vector<vector<char>> &g, pair<int, int> pos) {
    vector<vector<char>> copy(g);
    int currChar = copy[pos.first][pos.second];
    int nRows = copy.size();
    int nCols = copy[0].size();

    int minCol = nCols-1;
    for (int i = pos.first; i < nRows; i++) {
        for (int j = pos.second; j <= minCol; j++) {
            if (copy[i][j] == '.' or copy[i][j] == currChar)
                copy[i][j] = currChar;
            else {
                minCol = j-1;
                break;
            }
        }
    }

    minCol = nCols-1;
    for (int i = pos.first; i >= 0; i--) {
        for (int j = pos.second; j <= minCol; j++) {
            if (copy[i][j] == '.' or copy[i][j] == currChar)
                copy[i][j] = currChar;
            else {
                minCol = j-1;
                break;
            }
        }
    }

    int maxCol = 0;
    for (int i = pos.first; i < nRows; i++) {
        for (int j = pos.second; j >= maxCol; j--) {
            if (copy[i][j] == '.' or copy[i][j] == currChar)
                copy[i][j] = currChar;
            else {
                maxCol = j+1;
                break;
            }
        }
    }

    maxCol = 0;
    for (int i = pos.first; i >= 0; i--) {
        for (int j = pos.second; j >= maxCol; j--) {
            if (copy[i][j] == '.' or copy[i][j] == currChar)
                copy[i][j] = currChar;
            else {
                maxCol = j+1;
                break;
            }
        }
    }

    vector<pair<int,int>> preCalc(nRows);
    for (int i = 0; i < nRows; i++) {
        int l = INT_MAX, r = INT_MIN;
        for (int j = 0; j < nCols; j++) {
            if (copy[i][j] == currChar) {
                l = min(l, j);
                r = max(r, j);
            }
        }
        preCalc[i] = {l, r};
    }

    int maxArea = 0;
    pair<int, int> pse, psd, pie, pid;

    for (int startingRow = 0; startingRow < nRows; startingRow++) {
        for (int endingRow = 0; endingRow < nRows; endingRow++) {
            int l = max(preCalc[startingRow].first, preCalc[endingRow].first);
            int r = min(preCalc[startingRow].second, preCalc[endingRow].second);
            if (l > r) continue;
            int currArea = (r - l + 1) * (endingRow - startingRow + 1);
            if (currArea > maxArea) {
                maxArea = currArea;
                pse = {startingRow, l};
                psd = {startingRow, r};
                pie = {endingRow, l};
                pid = {endingRow, r};
            }
        }
    }

    for (int i = pse.first; i <= pid.first; i++) {
        for (int j = pse.second; j <= pid.second; j++) {
            if (g[i][j] != currChar) {
                g[i][j] = currChar + 32;
            }
        }
    }
}

int main() {
    optimize;
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> pos(26, {INF, INF});
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] != '.') {
                pos[g[i][j] - 'A'] = {i, j};
            }
        }
    }
    
    vector<int> v(25);
    iota(v.begin(), v.end(), 1);
    random_device rd;
    mt19937 mt(rd());

    while (true) {
        vector<vector<char>> copy(g);
        shuffle(v.begin(), v.end(), mt);

        expand(copy, pos[0]);
        for (int i = 0; i < 25; i++) {
            if (pos[v[i]].first != INF) {
                expand(copy, pos[v[i]]);
            }
        }
        if (check(copy)) {
            print(copy);
            break;
        }
    }

    return 0;
}