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
    int n;
    cin >> n;
    vector<bool> v(n);
    string s;
    f(i,0,n) {
        cin >> s;
        v[i] = s[0] == 'T';
    }
    
    stack<bool> st;
    while (cin >> s) {
        if (s[0] == '+') {
            bool el1 = st.top(); st.pop();
            bool el2 = st.top(); st.pop();
            st.push(el1 || el2);
        } else if (s[0] == '*') {
            bool el1 = st.top(); st.pop();
            bool el2 = st.top(); st.pop();
            st.push(el1 && el2);
        } else if (s[0] == '-') {
            bool el1 = st.top(); st.pop();
            st.push(!el1);
        } else {
            st.push(v[s[0]-'A']);
        }
    }
    cout << (st.top() ? "T" : "F") << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}