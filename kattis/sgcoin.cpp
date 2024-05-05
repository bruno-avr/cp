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

long long H(long long previousHash, string &transaction,
            long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

void solve() {
    vector<ll> res(100);
    string s = "z";
    ll n;
    cin >> n;
    f(j,0,2) {
        cout << s << " ";
        for (ll i = 0; i < 1e9; i++) {
            ll hash = H(n, s, i);
            if (hash % (ll)1e7 == 0) {
                n = hash;
                cout << i << endl;
                break;
            }
        }
    }
    
}

int main() {
    optimize;
    solve();

    return 0;
}