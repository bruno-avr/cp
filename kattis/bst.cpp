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
    ll n, a;
    cin >> n;
    ll cont = 0;
    vector<deque<int>> v(n+10);
    vector<int> depth(n+10);
    depth[0] = 0;
    set<ll> s;
    set<ll> negs;
    cin >> a;
    s.insert(a);
    negs.insert(-a);
    f(i,1,n) {
        cin >> a;
        cout << cont << endl;
        auto it = s.upper_bound(a);
        if (it == s.end()) {
            ll biggestEl = *(s.rbegin());
            v[biggestEl].push_back(a);
            depth[a] = depth[biggestEl] + 1;
            cont += depth[a];
            s.insert(a);
            negs.insert(-a);
            continue;
        }
        ll biggestEl = *it;
        
        it = negs.upper_bound(-a);
        if (it == negs.end()) {
            ll smallestEl = *(s.begin());
            v[smallestEl].push_front(a);
            depth[a] = depth[smallestEl] + 1;
            cont += depth[a];
            s.insert(a);
            negs.insert(-a);
            continue;
        }
        ll smallestEl = -1*(*it);
        
        if (depth[biggestEl] > depth[smallestEl]) {
            v[biggestEl].push_front(a);
            depth[a] = depth[biggestEl] + 1;
            cont += depth[a];
            s.insert(a);
            negs.insert(-a);
            continue;
        }
        v[smallestEl].push_back(a);
        depth[a] = depth[smallestEl] + 1;
        cont += depth[a];
        s.insert(a);
        negs.insert(-a);
    }
    cout << cont << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}