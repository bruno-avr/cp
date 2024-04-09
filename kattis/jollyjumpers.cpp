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

bool check(int n) {
    vector<int> v(n);
    f(i,0,n) {
        cin >> v[i];
    }
    vector<bool> v2(n-1, false);
    f(i,1,n) {
        int diff = abs(v[i]-v[i-1])-1;
        try {
            if (v2.at(diff)) return false;
            v2.at(diff) = true;
        } catch (const out_of_range &e) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    while (cin >> n) {
        if (check(n)) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
    }
 }

int main() {
    optimize;
    solve();

    return 0;
}