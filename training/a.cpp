#include "bits/stdc++.h"
using namespace std;

#define ll long long

int n;
string type;
vector<int> graph[100*100+10];
string s[101];
bool visited[100*100+10];

void add(int i, int j, int x, int y) {
    if (x >= 0 && x < n)
        if (y >= 0 && y < n)
            if (s[x][y] != '.')
                graph[100*(i)+(j)].push_back(100*(x)+(y));
}

void hook(int i, int j) {
    for (int a = 0; a < i; a++) add(i, j, a, j); // up
    for (int a = i+1; a < n; a++) add(i, j, a, j); // down
    for (int a = 0; a < j; a++) add(i, j, i, a); // left
    for (int a = j+1; a < n; a++) add(i, j, i, a); // right
}

void queen(int i, int j) {
    for (int a = 0; a < i; a++) add(i, j, a, j); // up
    for (int a = i+1; a < n; a++) add(i, j, a, j); // down
    for (int a = 0; a < j; a++) add(i, j, i, a); // left
    for (int a = j+1; a < n; a++) add(i, j, i, a); // right

    int thisI, thisJ;

    thisI = i-1; thisJ = j-1; // up-left
    while (thisI >= 0 && thisJ >= 0) add(i, j, thisI--, thisJ--);

    thisI = i-1; thisJ = j+1; // up-right
    while (thisI >= 0 && thisJ < n) add(i, j, thisI--, thisJ++);

    thisI = i+1; thisJ = j-1; // bottom-left
    while (thisI < n && thisJ >= 0) add(i, j, thisI++, thisJ--);

    thisI = i+1; thisJ = j+1; // bottom-right
    while (thisI < n && thisJ < n) add(i, j, thisI++, thisJ++);
}

void bishop(int i, int j) {
    int thisI, thisJ;

    thisI = i-1; thisJ = j-1; // up-left
    while (thisI >= 0 && thisJ >= 0) add(i, j, thisI--, thisJ--);

    thisI = i-1; thisJ = j+1; // up-right
    while (thisI >= 0 && thisJ < n) add(i, j, thisI--, thisJ++);

    thisI = i+1; thisJ = j-1; // bottom-left
    while (thisI < n && thisJ >= 0) add(i, j, thisI++, thisJ--);

    thisI = i+1; thisJ = j+1; // bottom-right
    while (thisI < n && thisJ < n) add(i, j, thisI++, thisJ++);
}

void knight(int i, int j) {
    add(i, j, i-2, j-1);
    add(i, j, i-2, j+1);
    add(i, j, i-1, j-2);
    add(i, j, i-1, j+2);
    add(i, j, i+1, j-2);
    add(i, j, i+1, j+2);
    add(i, j, i+2, j-1);
    add(i, j, i+2, j+1);
}

void king(int i, int j) {
    add(i, j, i-1, j-1);
    add(i, j, i-1, j);
    add(i, j, i-1, j+1);
    add(i, j, i, j-1);
    add(i, j, i, j+1);
    add(i, j, i+1, j-1);
    add(i, j, i+1, j);
    add(i, j, i+1, j+1);
}

int dfs(int x) {
    visited[x] = true;
    int numVisited = 1;
    for (auto viz : graph[x]) {
        if (!visited[viz]) {
            numVisited += dfs(viz);
        }
    }
    return numVisited;
}

void printRes(int x, int parent) {
    visited[x] = true;
    for (auto viz : graph[x]) {
        if (!visited[viz]) {
            printRes(viz, x);
        }
    }
    if (x != parent) {
        cout << (x/100)+1 << " " << (x%100)+1 << " " << (parent/100)+1 << " " << (parent%100)+1 << endl;
    }
}


int main() {
    cin >> n >> type;
    
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> vpos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != '.') {
                vpos.push_back(100*i + j);
                if (type == "R") hook(i, j);
                else if (type == "Q") queen(i, j);
                else if (type == "B") bishop(i, j);
                else if (type == "N") knight(i, j);
                else if (type == "K") king(i, j);
                else assert(false);
            }
        }
    }

    memset(visited, 0, sizeof visited);
    int numVisited = dfs(vpos[0]);

    memset(visited, 0, sizeof visited);

    if (numVisited == vpos.size()) {
        cout << "YES" << endl;
        printRes(vpos[0], vpos[0]);
        return 0;
    }

    cout << "NO" << endl;

    return 0;
}