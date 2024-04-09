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

ll getDigit (ll n, ll pos) {
    return (n & (((1<<16)-1)<<(pos*16l))) >> (pos*16l);
}

void countingSort(vector<ll> &v, ll pos) {
    vector<vector<ll>> counter((1<<16));
    vector<ll> prefix((1<<16));

    f(i,0,v.size()) counter[getDigit(v[i],pos)].push_back(v[i]);
    prefix[0] = counter[0].size();
    f(i,1,prefix.size()) prefix[i] = counter[i].size() + prefix[i-1];

    for (ll i = counter.size()-1; i >= 0; i--) {
        while (counter[i].size()) {
            v[--prefix[i]] = counter[i].back();
            counter[i].pop_back();
        }
    }
}

void radixSort(vector<ll> &v) {
    ll numChars = 2;
    for (ll i = 0; i < numChars; i++) {
        countingSort(v, i);
    }
}

void solve() {
    ll n, a, b, c, x, y;
    cin >> n >> a >> b >> c >> x >> y;
    vector<ll> v(n);
    v[0] = a;
    f(i,1,n) {
        v[i] = (ll)(((ll)v[i-1]*(ll)b+(ll)a)%(ll)c);
    }
    radixSort(v);
    ll value = 0;
    f(i,0,n) {
        // cout << v[i] << " ";
        value = (value * x + v[i]) % y;
    }
    cout << value << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}