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
    ll d;
    cin >> d;
    vector<ll> v(d);
    f(i,0,d) {
        cin >> v[i];
    }
    v.push_back(-1);
    ll currMoney = 100;
    ll numStocks = 0;
    f(i,0,d) {
        if (v[i+1] > v[i]) {
            ll curr = currMoney/v[i];
            if (curr + numStocks > 100000) curr = 100000 - numStocks;
            numStocks += curr;
            currMoney -= curr * v[i];
        }
        if (v[i+1] < v[i]) {
            currMoney += numStocks * v[i];
            numStocks = 0;
        }
    }
    cout << currMoney << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}