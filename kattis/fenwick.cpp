#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

typedef long long ll;                            // for extra flexibility
typedef vector<ll> vll;
typedef vector<int> vi;
#define ld long double
#define pii pair<ll,ll>

#define fi first
#define se second
#define pb push_back

#define all(x) x.begin(),x.end()

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 998244353LL

void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

#define LSOne(S) ((S) & -(S))                    // the key operation

class FenwickTree {                              // index 0 is not used
private:
  vll ft;                                        // internal FT is an array
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }      // create an empty FT

  ll rsq(int j) {                                // returns RSQ(1, j)
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }
};

void solve() {
    ll n, q, i, inc;
    cin >> n >> q;
    string op;
    FenwickTree ft(n+1);
    while (q--) {
        cin >> op >> i; i++;
        if (op == "+") {
            cin >> inc;
            ft.update(i, inc);
        } else {
            cout << ft.rsq(i-1) << endl;
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}