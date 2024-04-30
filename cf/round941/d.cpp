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
    int n, k;
    cin >> n >> k;
    vector<int> v;
    int m = 0;
    while(v.size() < 25) {
        if ((k == n) && (m >= n-1)) break;
        if (m >= n) break;
        int newM = 2*m+1;
        int pos = m+1;
        // cout << "newM " << newM << endl;
        // cout << "pos " << pos << endl;
        // cout << "m" << m << endl;
        if (k > m && k <= 2*m+1) {
            // cout << "here" << endl;
            // cout << "pos " << pos << endl;
            pos -= (newM)-(k)+1;
            newM = k;
        }
        if (pos > 0) v.push_back(pos);
        if (pos > k) {
            v.push_back(pos+k);
            newM += k;
        }
        m = newM;
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++) {
        if (i != 0) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}