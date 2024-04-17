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

    int root = (1<<(n+1))-1;

    if (cin >> s) {
        int pos = 0;
        int level = 1;
        for (char &c : s) {
            pos <<= 1;
            root -= (1 << level++);
            if (c == 'L') {
                pos++;
            }
        }
        cout << root+pos << endl;
    } else {
        cout << root << endl;
    }

}

int main() {
    optimize;
    solve();

    return 0;
}