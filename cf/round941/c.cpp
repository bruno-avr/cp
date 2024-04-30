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
    int n, a, m = 0;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a;
        m = max(a, m);
        s.insert(a);
    }
    int i = 0;
    bool aliceWin = 1;
    vector<int> v(s.size());
    for (auto el : s) {
        v[i++] = el;
    }
    if (v[0] == 1 && v.size() > 1) {
        aliceWin = !aliceWin;
        for(int j = 1; j < v.size()-1; j++) {
            if (v[j] != v[j-1]+1) break;
            aliceWin = !aliceWin;
        }
    }
    if (aliceWin) cout << "Alice" << endl;
    else cout << "Bob" << endl;
    
    
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}