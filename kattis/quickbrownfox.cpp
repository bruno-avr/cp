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
    vector<bool> v(26, false);
    for (char &c : line) {
        if (isalpha(c)) {
            c = tolower(c);
            v[c-'a'] = true;
        }
    }
    bool check = true;
    for (auto el : v) {
        if (!el) check = false;
    }
    if (check) cout << "pangram" << endl;
    else {
        cout << "missing ";
        for (int i = 0; i < v.size(); i++) {
            if (!v[i]) cout << char('a' + i);
        }
        cout << endl;
    }
}

int main() {
    optimize;
    int T;
    cin >> T;
    cin.ignore();

    while (T--) solve();

    return 0;
}