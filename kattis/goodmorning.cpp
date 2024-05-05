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

bool isPossible(int k) {
    string s = to_string(k);
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '0') if (!((s[i-1] != '9') && (s[i-1] != '6') && (s[i-1] != '3'))) return false;
        if (s[i] == '1') if (!((s[i-1] == '1'))) return false;
        if (s[i] == '2') if (!((s[i-1] == '1') || (s[i-1] == '2'))) return false;
        if (s[i] == '3') if (!((s[i-1] == '1') || (s[i-1] == '2') || (s[i-1] == '3'))) return false;
        if (s[i] == '4') if (!((s[i-1] == '1') || (s[i-1] == '4'))) return false;
        if (s[i] == '5') if (!((s[i-1] == '1') || (s[i-1] == '2') || (s[i-1] == '4') || (s[i-1] == '5'))) return false;
        if (s[i] == '6') if (!((s[i-1] == '1') || (s[i-1] == '2') || (s[i-1] == '3') || (s[i-1] == '4') || (s[i-1] == '5') || (s[i-1] == '6'))) return false;
        if (s[i] == '7') if (!((s[i-1] == '1') || (s[i-1] == '4') || (s[i-1] == '7'))) return false;
        if (s[i] == '8') if (!((s[i-1] == '1') || (s[i-1] == '2') || (s[i-1] == '4') || (s[i-1] == '5') || (s[i-1] == '7') || (s[i-1] == '8'))) return false;
        if (s[i] == '9') if (!((s[i-1] == '1') || (s[i-1] == '2') || (s[i-1] == '3') || (s[i-1] == '4') || (s[i-1] == '5') || (s[i-1] == '6') || (s[i-1] == '7') || (s[i-1] == '8') || (s[i-1] == '9'))) return false;
    }
    return true;
}

void solve() {
    int k;
    cin >> k;
    int curr = 0;
    for (int i = 0; i < 10000; i++) {
        if (isPossible(i)) {
            if (abs(k-i) < abs(k-curr)) {
                curr = i;
            }
        }
    }
    cout << curr << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}