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
    int n, s, r, a;
    cin >> n >> s >> r;
    vector<int> v(n);
    f(i,0,s) {
        cin >> a; a--;
        v[a]--;
    }
    f(i,0,r) {
        cin >> a; a--;
        v[a]++;
    }
    int cont = 0;
    f(i,0,n) {
        if (v[i] == -1) {
            if (i > 1 && v[i-1] == 1) {
                v[i] = 0;
                v[i-1] = 0;
            }
            else if (i < n-1 && v[i+1] == 1) {
                v[i] = 0;
                v[i+1] = 0;
            }
            else cont++;
        }
    }
    cout << cont << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}