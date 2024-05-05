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

void print (int pos, int val) {
    if (val == 0) return;
    if (pos == 1) cout << "single ";
    if (pos == 2) cout << "double ";
    if (pos == 3) cout << "triple ";
    cout << val << endl;
}

void solve() {
    int n;
    cin >> n;
    f(i,0,21)
    f(j,0,21)
    f(k,0,21)
    f(a,1,4)
    f(b,1,4)
    f(c,1,4) {
        if (i*a+j*b+k*c == n) {
            print(a,i);
            print(b,j);
            print(c,k);
            return;
        } 
    }
    cout << "impossible" << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}