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
    list<char> l;
    auto it = l.end();
    for(char &c : s) {
        if (c == '<') {
            if (!l.size() || it == l.begin()) continue;
            auto toErase = it;
            toErase--;
            l.erase(toErase);
        } else if (c == '[') {
            if (!l.size()) it = l.end();
            else {
                it = l.begin();
            }
        } else if (c == ']') {
            it = l.end();
        } else {
            l.insert(it, c);
        }
    }
    for (auto &c : l) {
        cout << c;
    }
    cout << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;
    cin.ignore();

    while (T--) solve();

    return 0;
}