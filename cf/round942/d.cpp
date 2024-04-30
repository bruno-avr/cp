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
    int n, m;
    cin >> n >> m;
    int cont = n;

    for (int b = 2; ((b*b <= (m+n)) and (b <= m)); b++) {
        int b2 = b*b;
        int a = b2-b;
        while(a <= n) {
            cont++;
            a += b2;
        }
    }
    cout << cont << endl;


}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}