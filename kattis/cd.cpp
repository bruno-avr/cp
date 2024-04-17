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
    int n, m, a;
    while (cin >> n >> m, n || m) {
        int cont = 0;
        unordered_set<int> s;
        f(i,0,n) {
            cin >> a;
            s.insert(a);
        }
        f(i,0,m) {
            cin >> a;
            if (s.count(a)) cont++;
        }
        cout << cont << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}