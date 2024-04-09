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
    vector<int> v(n);
    f(i,0,n) {
        cin >> v[i];
    }
    for (int i = n-2; i >= 0; i--) {
        if (v[i] > v[i+1]) {
            if (v[i] < 10) {
                no();
                return;
            }
            string s = to_string(v[i]);
            for (int i = 1; i < s.length(); i++) {
                if (s[i] < s[i-1]) {
                    no();
                    return;
                }
            }
            if ((s[s.length()-1] - '0') > v[i+1]) {
                no();
                return;
            }
            v[i] = s[0] - '0';
        }
    }
    yes();
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}