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
    string s1, s2;
    cin >> s1 >> s2;
    while (1) {
        if (!s1.size() or !s2.size()) break;
        if (s1.back() != s2.back()) break;
        s1.pop_back();
        s2.pop_back();
    }
    reverse(all(s1));
    reverse(all(s2));
    while (1) {
        if (!s1.size() or !s2.size()) break;
        if (s1.back() != s2.back()) break;
        s1.pop_back();
        s2.pop_back();
    }
    cout << s2.size() << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}