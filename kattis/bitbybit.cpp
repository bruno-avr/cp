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
    int n, i, j;
    string inst;
    while (cin >> n, n) {
        string v(32, '?');
        for (int k = 0; k < n; k++) {
            cin >> inst >> i;
            if (inst == "CLEAR") {
                v[i] = '0';
            } else if (inst == "SET") {
                v[i] = '1';
            } else if (inst == "OR") {
                cin >> j;
                if (v[i] == '1' || v[j] == '1') {
                    v[i] = '1';
                } else if (v[i] == '0' && v[j] == '0') {
                    v[i] = '0';
                } else {
                    v[i] = '?';
                }
            } else {
                cin >> j;
                if (v[i] == '1' && v[j] == '1') {
                    v[i] = '1';
                } else if (v[i] == '0' || v[j] == '0') {
                    v[i] = '0';
                } else {
                    v[i] = '?';
                }
            }
        }
        reverse(all(v));
        cout << v << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}