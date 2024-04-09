#include "bits/stdc++.h"

#define ll long long

using namespace std;

string CheckDOM(string str) {
  vector<string> tokens;
  
  string newToken;
  for (char &c : str) {
    if (c == '<') newToken = "";
    else if (c == '>') tokens.push_back(newToken);
    else newToken += c;
  }

  string toBeChanged = "";
  stack<string> st;
  for (string &token : tokens) {
    if (token[0] == '/') {
      if (!st.size()) return "false";
      if (st.top() == token.substr(1)) st.pop();
      else if (toBeChanged != "") return "false";
      else {
        toBeChanged = st.top();
        st.pop();
      }
    } else {
      st.push(token);
    }
  }

  if (st.size()) return "false";
  if (toBeChanged == "") return "true";
   
  return toBeChanged;

}

void solve() {
    string str;
    getline(cin, str);
    // cout << str << endl;
    cout << CheckDOM(str) << endl;
}

int main() {
    ll t;
    cin >> t;
    cin.ignore();

    while (t--) solve();

    return 0;
}