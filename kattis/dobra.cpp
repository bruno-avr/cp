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

ll sum = 0;

bool isV(char &c) {
    return ((c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U') || (c == '.'));
}

ll check(string &s) {
    bool possible = true;
    if (s.size() > 2)
        for (ll i = 0; i < s.size()-2; i++) {
            if (isV(s[i]) && isV(s[i+1]) && isV(s[i+2])) possible = false;
            if (!isV(s[i]) && !isV(s[i+1]) && !isV(s[i+2])) possible = false;
        }

    bool hasL = false;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == 'L') hasL = true;
    }
    if (!hasL) possible = false;
    if (!possible) return -1;
    ll possibilities = 1;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == '.') possibilities *= 5;
        if (s[i] == '#') possibilities *= 20;
    }
    return possibilities;
}

void func(string &s, ll pos) {
    if (pos == s.size()) {
        ll c = check(s);
        if (c != -1) sum += c;
        return;
    }
    if (s[pos] == '_') {
        s[pos] = '#';
        func(s, pos+1);
        s[pos] = '.';
        func(s, pos+1);
        s[pos] = 'L';
        func(s, pos+1);
        s[pos] = '_';
    } else {
        func(s, pos+1);
    }
}

void solve() {
    string s;
    cin >> s;
    func(s, 0);
    cout << sum << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}