#include "bits/stdc++.h"
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<stack<pair<int,int>>> v(26);
    stack<pair<int,int>> s;
    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line);

        for (int c = 0; c <= line.size(); c++) {
            if (line[c] == '{') {
                s.push({i, c+1});
            }
            if (line[c] >= 'a' && line[c] <= 'z') {
                if (!v[line[c]-'a'].empty()) {
                    cout << i << ":" << c+1 << ": warning: shadowed declaration of " << line[c];
                    cout << ", the shadowed position is " << v[line[c]-'a'].top().first << ":" << v[line[c]-'a'].top().second << endl;
                }
                v[line[c]-'a'].push({i, c+1});
            }
            if (line[c] == '}') {
                auto pos = s.top(); s.pop();
                for (int j = 0; j < 26; j++) {
                    if (!v[j].empty() and v[j].top() > pos) {
                        v[j].pop();
                    }
                }
            }
        }
    }
    
    return 0;
}