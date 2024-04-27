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
        void build(const vi &f) {
            int m = (int)f.size()-1;
            ft.assign(m+1, 0);
            for (int i = 1; i <= m; ++i) {
                ft[i] += f[i];
                if (i+LSOne(i) <= m)
                    ft[i+LSOne(i)] += ft[i];
            }
        }
        FenwickTree(const vi &f) { build(f); }
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
    int m, r, a;
    cin >> m >> r;
    vi pos(m);
    iota(all(pos), r+1);
    vi movies(m+r+1, 0);
    f(i,r+1,m+r+1) movies[i] = 1;
    FenwickTree ft(movies);
    f(i,0,r) {
        int currPos = r-i;
        cin >> a;
        if (i != 0) cout << " ";
        cout << ft.rsq(1, pos[a-1])-1;
        ft.update(pos[a-1], -1);
        ft.update(currPos, 1);
        pos[a-1] = currPos;
    }
    cout << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}