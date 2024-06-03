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

int n;

bool p(set<pair<int,int>> &s, int k) {
    int curr = n-k;
    vector<int> res(n, -1);
    for (int i = curr; i < n; i++) {
        auto it = s.end();
        it--;
        auto &[val, pos] = (*it);
        int left = res[pos-1];
        int right = res[pos+1];

    }
    return true;
}

void solve() {
    cin >> n;
    vector<int> v(n);
    vector<int> rev(n);
    vector<int> res(n, -1);
    set<pair<int,int>> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        rev[--v[i]] = i;
        if (i < 0 && i < n-1) s.insert({v[i], i});
    }
    
    
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}