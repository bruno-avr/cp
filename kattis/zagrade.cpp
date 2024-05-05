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

void solve() {
    string s;
    getline(cin, s);
    vector<int> open;
    stack<int> st;
    unordered_map<int,int> close;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            open.push_back(i);
            st.push(i);
        }
        if (s[i] == ')') {
            close[st.top()] = i;
            st.pop();
        }
    }
    int subs = (1<<open.size()) - 1;
    set<string> res;
    for (int i = subs; i; i = (i-1)&subs) {
        bool possible = true;
        unordered_set<int> toRemove;
        for (int j = 0; j < open.size(); j++) {
            if (i & (1 << j)) {
                toRemove.insert(open[j]);
                toRemove.insert(close[open[j]]);
            }
        }
        string newOp = "";
        for (int j = 0; j < s.size(); j++) {
            if (toRemove.count(j) == 0) {
                newOp += s[j];
            }
        }
        res.insert(newOp);
    }
    for (auto &el : res) {
        cout << el << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}