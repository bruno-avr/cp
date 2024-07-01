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

    int test = 0;
    bool adding = 1;
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '(' or c == ')') {
            if (st.size() && st.top() == 0) {
                adding = 0;
                st.pop();
            } else {
                if (!adding) return false;
                st.push(0);
            }
        } else {
            if (st.size() && st.top() == 1) {
                adding = 0;
                st.pop();
            } else {
                if (!adding) return false;
                st.push(1);
            }
        }
        if (st.empty()) {
            adding = true;
            if (test > 1) return false;
            if (test == 1) {
                int curr;
                if (c == '(' or c == ')') curr = 0;
                else curr = 1;
                int first;
                if (s[0] == '(' or s[0] == ')') first = 0;
                else first = 1;
                if (first == curr) return false;
            }
            test++;
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