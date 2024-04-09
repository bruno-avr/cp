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
    int n, m;
    string s;
    bool first = true;
    while (cin >> n, n) {
        stack<int> s1, s2;
        if (first) first = false;
        else cout << endl;
        f(i, 0, n) {
            cin >> s >> m;
            if (s == "DROP") {
                cout << "DROP 1 " << m << endl;
                s1.push(m);
            }
            if (s == "TAKE") {
                int total = 0;
                while (s2.size() && m) {
                    int curr = s2.top(); s2.pop();
                    if (curr > m) {
                        s2.push(curr-m);
                    }
                    total += min(m, curr);
                    m -= min(m, curr);
                }
                if (total) cout << "TAKE 2 " << total << endl;
                
                if (m) {
                    int thisTotal = 0;
                    while (s1.size()) {
                        thisTotal += s1.top();
                        s2.push(s1.top());
                        s1.pop();
                    }
                    cout << "MOVE 1->2 " << thisTotal << endl;
                }

                total = 0;
                while (s2.size() && m) {
                    int curr = s2.top(); s2.pop();
                    if (curr > m) {
                        s2.push(curr-m);
                    }
                    total += min(m, curr);
                    m -= min(m, curr);
                }
                if (total) cout << "TAKE 2 " << total << endl;
            }
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}