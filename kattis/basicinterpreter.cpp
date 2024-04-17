#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
#define ld long double
#define pii pair<ll,ll>

#define fi first
#define se second
#define pb push_back

#define all(x) x.begin(),x.end()

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 998244353LL

#define f(i,s,e) for(ll i=s;i<e;i++)
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

unordered_map<string, int> vars;

int getVar(string var) {
    if (vars.find(var) == vars.end()) return stoi(var);
    return vars[var];
}

bool cmp (const string &s1, const string &s2) {
    stringstream ss1;
    stringstream ss2;
    ss1 << s1;
    ss2 << s2;
    int n1, n2;
    ss1 >> n1;
    ss2 >> n2;
    return n1 < n2;
}

void solve() {
    string line;
    vector<int> labels;
    unordered_map<int, int> nextLabel;
    unordered_map<int, string> linePerLabel;
    vector<string> lines;
    while(getline(cin, line)) {
        lines.push_back(line);
    }
    sort(all(lines), cmp);
    for(auto &line : lines) {
        int label;
        stringstream ss;
        ss << line;
        ss >> label;
        linePerLabel[label] = line;
        labels.push_back(label);
    }
    for (int i = 0; i < labels.size(); i++) {
        nextLabel[labels[i]] = i+1 == labels.size() ? -1 : labels[i+1];
    }
    int currLabel = labels[0];

    while(currLabel != -1) {
        stringstream ss;
        ss << linePerLabel[currLabel];
        int label, newLabel;
        string cmd, var1, var2, var3, aux, op, condition;

        ss >> label >> cmd;
        if (cmd == "LET") {
            ss >> var1 >> aux >> var2;
            int sum = getVar(var2);
            if (ss >> op >> var3) {
                int el = getVar(var3);
                if (op == "+") sum += el;
                if (op == "-") sum -= el;
                if (op == "*") sum *= el;
                if (op == "/") sum /= el;
            }
            vars[var1] = sum;
            currLabel = nextLabel[currLabel];
        } else if (cmd == "IF") {
            ss >> var1 >> condition >> var2 >> aux >> aux >> newLabel;
            if (condition == "=" && (getVar(var1) == getVar(var2))) currLabel = newLabel;
            else if (condition == "=" && (getVar(var1) == getVar(var2))) currLabel = newLabel;
            else if (condition == ">" && (getVar(var1) > getVar(var2))) currLabel = newLabel;
            else if (condition == "<" && (getVar(var1) < getVar(var2))) currLabel = newLabel;
            else if (condition == "<>" && (getVar(var1) != getVar(var2))) currLabel = newLabel;
            else if (condition == "<=" && (getVar(var1) <= getVar(var2))) currLabel = newLabel;
            else if (condition == ">=" && (getVar(var1) >= getVar(var2))) currLabel = newLabel;
            else currLabel = nextLabel[currLabel];
        } else {
            string rest;
            getline(ss, rest);
            rest = rest.substr(1);
            if (rest[0] == '"') {
                cout << rest.substr(1, rest.size()-2);
            } else {
                cout << getVar(rest);
            }
            if (cmd == "PRINTLN") cout << endl;
            currLabel = nextLabel[currLabel];
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}