#include "bits/stdc++.h"
using namespace std;

#include "bits/extc++.h"
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

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
    string s;
    ost tree;
    while (cin >> s) {
        if (s == "#") {
            auto m = tree.find_by_order(tree.size()/2);
            cout << *m << endl;
            tree.erase(m);
        } else {
            tree.insert(stoi(s));
        }
    }
}

int main() {
    optimize;
    int T = 1;

    while (T--) solve();

    return 0;
}