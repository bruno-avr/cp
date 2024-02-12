#include "bits/stdc++.h"
#define ll long long

using namespace std;
const int MAXN = 200010;
vector<vector<int>> graph(MAXN);
vector<vector<int>> edgeId(MAXN);
vector<bool> visited(MAXN, false);
vector<int> profs(MAXN, 0);

vector<vector<int>> days(MAXN);

void dfs(int x, int invalidDay) {
    visited[x] = 1;
    
    int dayId = 0;
    for (int i = 0; i < graph[x].size(); i++) {
        int viz = graph[x][i];
        if (!visited[viz]) {
            if (dayId == invalidDay) dayId++;
            days[dayId].push_back(edgeId[x][i]+1);
            dfs(viz, dayId++);
        }
    }
}

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edgeId[a].push_back(i);
        edgeId[b].push_back(i);
    }

    int maxDegree = 0;
    for (int i = 0; i < n; i++) maxDegree = max(maxDegree, (int)(graph[i].size()));

    dfs(0, -1);

    cout << maxDegree << endl;

    for (int i = 0; i < maxDegree; i++) {
        cout << days[i].size();
        for (int el : days[i]) cout << " " << el;
        cout << endl;
    }
    
    return 0;
}