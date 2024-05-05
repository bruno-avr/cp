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
    string line;
    getline(cin, line);
    int k = 1;
    for (auto &c : line) {
        if (c == ' ') k++;
    }
    
    int n;
    cin >> n;
    vector<string> names(n);
    f(i,0,n) {
        cin >> names[i];
    }
    int pos = n-1;
    vector<string> g1, g2;
    bool first = true;
    for (int i = 0; i < n; i++) {
        int kaux = k;
        while (kaux--) {
            pos = (pos + 1) % n;
            while (names[pos] == "") {
                pos = (pos + 1) % n;
            }
        }
        if (first) {
            g1.push_back(names[pos]);
        } else {
            g2.push_back(names[pos]);
        }
        names[pos] = "";
        first = !first;
    }
    cout << g1.size() << endl;
    for (auto el : g1) {
        cout << el << endl;
    }
    cout << g2.size() << endl;
    for (auto el : g2) {
        cout << el << endl;
    }

}

int main() {
    optimize;
    solve();

    return 0;
}