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
    string line;

    cin.ignore();
    getline(cin, line);

    stack<char> st;
    int i = 0;
    for (char &c : line) {
        if (c == '(' or c == '[' or c == '{') st.push(c);
        else if (c == ')') {
            if (!st.size() || st.top() != '(') {
                cout << c << " " << i << endl;
                return;
            }
            st.pop();
        } else if (c == ']') {
            if (!st.size() || st.top() != '[') {
                cout << c << " " << i << endl;
                return;
            }
            st.pop();
        } else if (c == '}') {
            if (!st.size() || st.top() != '{') {
                cout << c << " " << i << endl;
                return;
            }
            st.pop();
        }
        i++;
    }
    cout << "ok so far" << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}