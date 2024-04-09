#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
#define all(x) x.begin(),x.end()

unordered_map<char, int> tab1;
vector<char> tab2;

void init () {
    int cont = 0;
    for (int i = '0'; i <= '9'; i++) {
        tab2.push_back(i);
        tab1[i] = cont++;
    }
    for (int i = 'a'; i <= 'z'; i++) {
        tab2.push_back(i);
        tab1[i] = cont++;
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        tab2.push_back(i);
        tab1[i] = cont++;
    }
}

void solve(vector<string> &v, int c) {
    unordered_map<char, pair<int,int>> charPos;
    int maxChar = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] != '.') {
                maxChar = max(maxChar, tab1[v[i][j]]);
                charPos[v[i][j]] = {i,j};
            }
        }
    }
    for (int i = 0; i < maxChar; i++) {
        auto &[x1, y1] = charPos[tab2[i]];
        auto &[x2, y2] = charPos[tab2[i+1]];
        for (int j = min(x1, x2)+1; j < max(x1, x2); j++) {
            if (v[j][y1] == '.') v[j][y1] = '|';
            if (v[j][y1] == '-') v[j][y1] = '+';
        }
        for (int j = min(y1, y2)+1; j < max(y1, y2); j++) {
            if (v[x1][j] == '.') v[x1][j] = '-';
            if (v[x1][j] == '|') v[x1][j] = '+';
        }
    }
    if (c) cout << endl;
    for (auto line : v) {
        cout << line << endl;
    }
}

int main() {
    optimize;
    init();
    
    string s;
    vector<string> v;
    int c = 0;
    while(getline(cin, s)) {
        if (s == "") {
            solve(v, c++);
            v.clear();
            continue;
        }
        v.push_back(s);
    }
    solve(v, c++);

    return 0;
}