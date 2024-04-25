#include "bits/stdc++.h"
using namespace std;

#include "bits/extc++.h"
using namespace __gnu_pbds;
typedef tree<tuple<int, int, int>, null_type, less<tuple<int, int, int>>, rb_tree_tag, tree_order_statistics_node_update> ost;

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
    int n, m, t, p;
    cin >> n >> m;
    ost tree;
    unordered_map<int, int> tq;
    unordered_map<int, int> tp;
    f(i,0,n) {
        tree.insert({0, 0, i+1});
    }
    f(i,0,m) {
        cin >> t >> p;
        tree.erase({-tq[t], tp[t], t});
        tp[t] += p;
        tq[t]++;
        tree.insert({-tq[t], tp[t], t});
        cout << tree.order_of_key({-tq[1], tp[1], 1}) + 1 << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}