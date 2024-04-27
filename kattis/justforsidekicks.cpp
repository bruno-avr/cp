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

#define LSOne(S) ((S) & -(S))
typedef vector<ll> vi;

class FenwickTree {
    // index 0 is not used
    private:
        vi ft;
    public:
        FenwickTree(ll m) { ft.assign(m+1, 0); } // create empty FT
        ll rsq(ll j) { // returns RSQ(1, j)
            ll sum = 0;
            for (; j; j -= LSOne(j))
                sum += ft[j];
            return sum;
        }
        ll rsq(ll i, ll j) { return rsq(j) - rsq(i-1); } // inc/exclusion
        // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
        void update(ll i, ll v) {
            for (; i < (ll)ft.size(); i += LSOne(i))
                ft[i] += v;
        }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> values(6);
    f(i,0,6) cin >> values[i];
    string s;
    cin >> s;
    vector<FenwickTree> ft(6, FenwickTree(n));
    vector<ll> gems(n);
    f(i,0,n) {
        gems[i] = s[i]-'1';
        ft[gems[i]].update(i+1, 1);
    }
    ll type, k, p;
    f(i,0,q) {
        cin >> type;
        if (type == 1) {
            cin >> k >> p;
            ft[gems[k-1]].update(k, -1);
            gems[k-1] = p-1;
            ft[gems[k-1]].update(k, 1);
        } else if (type == 2) {
            cin >> p >> k;
            values[p-1] = k;
        } else {
            cin >> p >> k;
            ll total = 0;
            f(j,0,6) {
                total += ft[j].rsq(p, k) * values[j];
            }
            cout << total << endl;
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}