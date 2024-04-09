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
    cin >> s;
    vector<vector<bool>> v(s.length(), vector<bool> (s.length(), false));
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            if (s[i] == s[j] || s[i] == '?' || s[j] == '?') {
                v[i][j] = true;
            }
        }
    }
    for (int i = s.length()/2; i >= 0; i--) {
        for (int j = 0; j < s.length(); j++) {
            if (j+2*i-1 >= s.length()) continue;
            bool can = true;
            for (int k = j; k < j+i; k++) {
                if (!v[k][k+i]) {
                    can = false;
                    break;
                }
            }
            if (can) {
                cout << 2*i << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}