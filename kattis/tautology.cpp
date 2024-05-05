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

bool getV(string &str, bool p, bool q, bool r, bool s, bool t) {
    stack<bool> st;
    for (auto &c : str) {
        if (c == 'N') {
            bool curr = st.top(); st.pop();
            st.push(!curr);
        } else if (c == 'K') {
            bool curr1 = st.top(); st.pop();
            bool curr2 = st.top(); st.pop();
            st.push(curr1 and curr2);
        } else if (c == 'A') {
            bool curr1 = st.top(); st.pop();
            bool curr2 = st.top(); st.pop();
            st.push(curr1 or curr2);
        } else if (c == 'C') {
            bool curr1 = st.top(); st.pop();
            bool curr2 = st.top(); st.pop();
            st.push(!(curr1 && !curr2));
        } else if (c == 'E') {
            bool curr1 = st.top(); st.pop();
            bool curr2 = st.top(); st.pop();
            st.push(curr1 == curr2);
        } else if (c == 'p') st.push(p);
        else if (c == 'q') st.push(q);
        else if (c == 'r') st.push(r);
        else if (c == 's') st.push(s);
        else if (c == 't') st.push(t);
    }
    return st.top();
}

bool isT(string &str) {
    reverse(all(str));
    bool check = true;
    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                for (int s = 0; s <= 1; s++) {
                    for (int t = 0; t <= 1; t++) {
                        if (!getV(str, p == 1, q == 1, r == 1, s == 1, t == 1)) {
                            check = false;
                        }
                    }
                }
            }
        }
    }
    return check;
}

void solve() {
    string s;
    while (cin >> s, s != "0") {
        if (isT(s)) cout << "tautology" << endl;
        else cout << "not" << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}