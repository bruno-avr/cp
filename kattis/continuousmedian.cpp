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
    long long n, a, total = 0;
    cin >> n;
    ost tree;
    for (int i = 0; i < n; i++) {
        cin >> a;
        tree.insert(a);
        if (i % 2 == 0) {
            total += *tree.find_by_order(i/2);
        } else {
            total += (*tree.find_by_order(i/2) + *tree.find_by_order(i/2+1))/2;
        }
    }
    cout << total << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}