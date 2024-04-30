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
    string s;
    cin >> n;
    cin >> s;
    vector<bool> v(n);
    if (s == "U") yes();
    else if (s == "D") no();
    else if (s == "UU") no();
    else if (s == "DD") no();
    else if (s == "UD") yes();
    else if (s == "DU") yes();
    else {
        int nu = 0;
        f(i,0,n) {
            v[i] = s[i] == 'U';
            if (s[i] == 'U') nu++;
        }
        if (nu == 0) no();
        else {
            if (n % 2 == 0) {
                if (nu % 2 == 0) {
                    yes();
                } else {
                    no();
                }
            } else {
                if (nu % 2 == 0) {
                    no();
                } else {
                    yes();
                }
            }
        }
        
    }

}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}