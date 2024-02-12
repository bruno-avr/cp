#include "bits/stdc++.h"
#define ll long long

using namespace std;

int nX[]{0, 1, 0, -1};
int nY[]{1, 0, -1, 0};

vector<vector<int>> component(1000, vector<int>(1000, -1));
vector<int> wallsInC(1000000, 0);

void dfs(vector<string> &graph, int x, int y, int componentId) {
    component[x][y] = componentId;

    int numNeighbors = 0;
    for (int i = 0; i < 4; i++) {
        int currX = x + nX[i];
        int currY = y + nY[i];
        if (currX < 0 || currY < 0 || currX > graph.size() || currY > graph[0].size()) continue;
        if (graph[currX][currY] == '.') {
            if (component[currX][currY] == -1)
                dfs(graph, currX, currY, componentId);
            numNeighbors++;
        }
    }
    wallsInC[componentId] += 4-numNeighbors;
}

int main() {
    int n, m, k, a, b;
    cin >> n >> m >> k;

    vector<string> graph(n);

    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }
    int compId = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (component[i][j] == -1 && graph[i][j] == '.') {
                dfs(graph, i, j, compId++);
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        cout << wallsInC[component[a][b]] << endl;
    }

    return 0;
}