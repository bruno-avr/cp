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
    string n, m;
    cin >> n >> m;
    while (true) {
        if (n.back() == '0' && m.back() == '0') {
            n.pop_back();
            m.pop_back();
        } else break;
    }
    int num0 = m.length()-1;
    if (!num0) {
        cout << n << endl;
        return;
    }
    reverse(all(n));
    while (n.size() < m.size()) {
        n.push_back('0');
    }
    reverse(all(n));
    cout << n.substr(0, n.size()-num0) << "." << n.substr(n.size()-num0, num0) << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}