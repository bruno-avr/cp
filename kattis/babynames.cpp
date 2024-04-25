#include "bits/stdc++.h"
using namespace std;

#include <bits/extc++.h>
// pbds
using namespace __gnu_pbds;
typedef tree<string, null_type, less<string>, rb_tree_tag,
    tree_order_statistics_node_update> ost;

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
    int c, gender, genderSuitability;
    string name, start, end;
    ost treeMale;
    ost treeFemale;
    while (cin >> c, c) {
        if (c == 1) {
            cin >> name >> gender;
            if (gender == 1) {
                treeMale.insert(name);
            } else {
                treeFemale.insert(name);
            }
        } else if (c == 2) {
            cin >> name;
            treeMale.erase(name);
            treeFemale.erase(name);
        } else {
            cin >> start >> end >> genderSuitability;
            int male = treeMale.order_of_key(end) - treeMale.order_of_key(start);
            int female = treeFemale.order_of_key(end) - treeFemale.order_of_key(start);
            if (genderSuitability == 0) cout << male + female << endl;
            else if (genderSuitability == 1) cout << male << endl;
            else cout << female << endl;
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}