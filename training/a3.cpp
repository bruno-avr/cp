#include "bits/stdc++.h"

using namespace std;

pair<int, int> calc(string &s) {
    int min0 = INT_MAX, min1 = INT_MAX;
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '(' or c == ')') {
            if (st.size() && st.top() == 0) {
                st.pop();
            } else st.push(0);
        } else {
            if (st.size() && st.top() == 1) {
                st.pop();
            } else st.push(1);
        }
        if (st.empty()) {
            if (c == '(' or c == ')') min0 = min(min0, i);
            else min1 = min(min1, i);
        }
    }
    return {min0, min1};
}

bool solve() {
    string s;
    cin >> s;
    auto [l0, l1] = calc(s);
    reverse(s.begin(), s.end());
    auto [r0, r1] = calc(s);
    r0 = s.size() - 1 - r0;
    r1 = s.size() - 1 - r1;
    // cout << "0: " << l0 << " " << r0 << endl;
    // cout << "1: " << l1 << " " << r1 << endl;

    if (r0 == INT_MAX) {
        if (r1 > l1) return false;
    } else if (r1 == INT_MAX) {
        if (r0 > l0) return false;
    } else if (r0 > l0 or r1 > l1) return false;
    // for (int i = 0; i <= (int)s.size()-3; i++) {
    //     int curr = (s[i] == '(' or s[i] == ')') ? 0 : 1;
    //     bool has3 = true;
    //     for (int j = 1; j < 3; j++) {
    //         int thisV;
    //         if (s[i+j] == '(' or s[i+j] == ')') thisV = 0;
    //         else thisV = 1;
    //         if (thisV != curr) {
    //             has3 = false;
    //             break;
    //         }
    //     }
    //     if (has3) return false;
    // }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cout << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}