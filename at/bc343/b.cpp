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

int main() {
    optimize;
    int n, a;
    cin >> n;
    vector<set<int>> v(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (a == 1) {
                v[i].insert(j);
                v[j].insert(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        bool first = true;
        for (auto el : v[i]) {
            if (first) first = false;
            else cout << " ";
            cout << el+1;
        }
        cout << endl;
    }

    return 0;
}