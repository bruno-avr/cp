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
    while (cin >> s1 >> s2, s1 != "0" || s2 != "0") {
        reverse(all(s1));
        reverse(all(s2));
        s1 += "0000000000";
        s2 += "0000000000";
        bool carry = 0;
        int total = 0;
        for (int i = 0; i < 11; i++) {
            carry = ((s1[i]-'0') + (s2[i]-'0') + (int)carry) > 9;
            if (carry) total++;
        }
        if (!total) {
            cout << "No carry operation." << endl;
        } else if (total == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << total << " carry operations." << endl;
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}