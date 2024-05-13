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
    int n, k, s, e;
    cin >> n >> k;
    vector<pair<int,int>> v(n);
    f(i,0,n) {
        cin >> s >> e;
        v[i] = {e, s};
    }
    sort(all(v));
    int res = 0;
    multiset<int> pq;
    f(i,0,k) pq.insert(0);
    f(i,0,n) {
        auto it = pq.upper_bound(-v[i].second);
        // cout << v[i].second << " " << *it << endl;
        if (it == pq.end()) continue;
        pq.erase(it);
        pq.insert(-v[i].first);
        res++;
    }
    cout << res << endl;
    
}

int main() {
    optimize;
    solve();

    return 0;
}