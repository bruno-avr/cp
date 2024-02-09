#include "bits/stdc++.h"
#define ll long long

using namespace std;
const int MAXN = 200010;
vector<vector<int>> graph(MAXN);
vector<bool> visited(MAXN, false);
vector<int> maxProfs(MAXN, 1);

void dfs(int x, int prof) {
    visited[x] = 1;
    for (auto viz : graph[x]) {
        if (!visited[viz]) {
            dfs(viz, prof+1);
            maxProfs[x] = max(maxProfs[x], maxProfs[viz]+1);
        }
    }
}

int main() {
    int n, k, a;
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        cin >> a;
        graph[a-1].push_back(i+1);
    }
    dfs(0, 0);

    priority_queue<pair<int, int>> pq;
    pq.push({maxProfs[0], 0});
    int total = 0;
    for (int i = 0; i < k; i++) {
        auto el = pq.top(); pq.pop();
        total += el.first;
        int curr = el.second;
        while (graph[curr].size()) {
            int maxEl = graph[curr][0];
            for (int j = 1; j < graph[curr].size(); j++) {
                int thisEl = graph[curr][j];
                if (maxProfs[thisEl] > maxProfs[curr]) continue; // parent
                if (maxProfs[thisEl] > maxProfs[maxEl]) {
                    pq.push({maxProfs[maxEl], maxEl});
                    maxEl = thisEl;
                } else {
                    pq.push({maxProfs[thisEl], thisEl});
                }
            }
            curr = maxEl;
        }
        if (pq.empty()) break;
    }
    cout << total << endl;
    
    return 0;
}