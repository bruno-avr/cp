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
    bool first = true;
    while(cin >> n, n) {
        if (first) first = false;
        else cout << endl;
        vector<tuple<string, int, string>> v(n);
        string aux;
        f(i,0,n) {
            cin >> aux;
            v[i] = {aux.substr(0,2), i, aux};
        }
        sort(all(v));
        for (auto &[a,b,c] : v) {
            cout << c << endl;
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}