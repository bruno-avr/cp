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

int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
void expand(vector<vector<char>> &g, pair<int, int> pos) {
    int currChar = g[pos.first][pos.second];
    queue<tuple<int,int,int,vector<bool>>> bfs;
    bfs.push({1,pos.first, pos.second, vector<bool>(8, true)});

    vector<vector<pair<int,int>>> pointsPerLayer(1010, vector<int>(4, {INT_MAX, INT_MAX}));
    while (!bfs.empty()) {
        auto [layer, x, y, canGo] = bfs.front(); bfs.pop();
        g[x][y] = currChar;
        for (int i = 0; i < 8; i++) {
            if (canGo[i]) {
                if (x+dx[i] < 0 or x+dx[i] >= g.size()) continue;
                if (y+dy[i] < 0 or y+dy[i] >= g[0].size()) continue;
                if (g[x+dx[i]][y+dy[i]] != '.') {
                    if (g[x+dx[i]][y+dy[i]] != 'A') {
                        maxHeightPerLayer[layer+1] = min(maxHeightPerLayer[layer])
                    }
                    continue;
                }
                vector<bool> possibilites(8, false);
                for (int j = 0; j < 8; j++) {
                    if (dx[i] != 0 && dy[i] != 0) {
                        if (dx[i] == dx[j] && (dy[i] == dy[j] or dy[j] == 0)) {
                            possibilites[j] = true;
                        }
                        if (dy[i] == dy[j] && (dx[i] == dx[j] or dx[j] == 0)) {
                            possibilites[j] = true;
                        }
                    } else if (dx[i] != 0 && dy[i] == 0) {
                        if (dx[i] == dx[j] && dy[i] == dy[j]) {
                            possibilites[j] = true;
                        }
                    } else if (dx[i] == 0 && dy[i] != 0) {
                        if (dx[i] == dx[j] && dy[i] == dy[j]) {
                            possibilites[j] = true;
                        }
                    }
                }
                // cout << i << " -";
                // for (int j = 0; j < 8; j++) {
                //     cout << " " << possibilites[j];
                // }
                // cout << endl;
                bfs.push({layer+1, x+dx[i], y+dy[i], possibilites});
                
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
    for (int i = 0; i < 26; i++) {
        if (pos[i].first != INF) {
            expand(g, pos[i]);
        }
    }
    
    print(g);

    return 0;
}