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
    int maxEquals = 0;
    for (int i = 0; i < s.size() - 3; i++) {
        int equals = 0;
        if (s[i] == 'O') equals++;
        if (s[i+1] == 'D') equals++;
        if (s[i+2] == 'O') equals++;
        if (s[i+3] == 'O') equals++;
        maxEquals = max(maxEquals, equals);
    }
    cout << s.size() - maxEquals << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}