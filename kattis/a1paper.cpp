#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
#define ld long long double
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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> hasEquivalent(n);
    hasEquivalent[0] = 0;
    int index = -1;
    for(int i = 1; i < n; i++) {
        cin >> v[i];
        hasEquivalent[i] = hasEquivalent[i-1] * 2 + v[i];
        if (hasEquivalent[i] >= (1<<i)) {
            v[i] = (1<<i) - 2*hasEquivalent[i-1];
            if (index == -1) index = i;
        }
    }
    if (index == -1) {
        cout << "impossible" << endl;
        return;
    }
    vector<pair<long double,long double>> vp(index+1);
    vp[1] = {pow(2.0,-5.0/4.0), pow(2.0,-3.0/4.0)};
    f(i,2,index+1) {
        vp[i] = vp[i-1];
        if (vp[i].first > vp[i].second) vp[i].first /= 2.0;
        else vp[i].second /= 2.0;
    }
    long double total = 0;
    for (int i = index; i >= 1; i--) {
        while (v[i] != 0) {
            v[i-1]++;
            v[i]-=2;
            total += max(vp[i].first, vp[i].second);
        }
    }
    cout << fixed << setprecision(10) << total << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}