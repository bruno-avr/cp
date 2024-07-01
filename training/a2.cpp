#include "bits/stdc++.h"

using namespace std;

bool solve() {
    string s;
    cin >> s;
    stack<int> st;
    int n0 = 0, n1 = 0;
    for (char c : s) {
        if (c == '(' or c == ')') n0++;
        else n1++;
    }
    int n0a = 0, n1a = 0;
    for (char c : s) {
        if (c == '(' or c == ')') {
            if (st.size() && st.top() == 0) {
                if (n0a < n0/2) return false;
                else st.pop();
            } else st.push(0);
            n0a++;
        }
        else {
            if (st.size() && st.top() == 1) {
                if (n1a < n1/2) return false;
                else st.pop();
            } else st.push(1);
            n1a++;
        }
    }
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