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

const ll mod = 1e9 + 7;

#define f(i,s,e) for(ll i=s;i<e;i++)
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

ll power(ll x, unsigned ll y)
{
    ll res = 1; // Initialize result
 
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x)% mod;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % mod; // Change x to x^2
    }
    return res;
}

void solve() {
    ll v, e, q, a, b;
    cin >> v >> e >> q;
    vector<vector<bool>> am(v+2001, vector<bool>(v+2001, false));
    ll op;
    f(i,0,e) {
        cin >> a >> b;
        am[a][b] = true;
    }
    bool transpose = false;
    bool complement = false;
    f(i,0,q) {
        cin >> op;
        if (op == 1) {
            if (complement) {
                f(j, 0, v) {
                    am[v][j] = true;
                    am[j][v] = true;
                }
            }
            v++;
        } else if (op == 2) {
            cin >> a >> b;
            if (transpose) am[b][a] = complement ? false : true;
            else am[a][b] = complement ? false : true;
        } else if (op == 3) {
            cin >> a;
            f(j, 0, v) {
                am[a][j] = complement;
                am[j][a] = complement;
            }
        } else if (op == 4) {
            cin >> a >> b;
            if (transpose) am[b][a] = complement ? true : false;
            else am[a][b] = complement ? true : false;
        } else if (op == 5) {
            transpose = !transpose;
        } else {
            complement = !complement;
        }
    }
    cout << v << endl;
    vector<ll> outDegree(am.size(), 0);
    vector<ll> sum(am.size(), 0);
    vector<ll> numNei(am.size(), 0);
    f(i, 0, v) {
        f(j, 0, v) {
            if (i == j) continue;
            if (complement ? (!am[i][j]) : am[i][j]) {
                if (transpose) {
                    outDegree[j]++;
                    sum[j] = (sum[j] + (((power(7, numNei[j]++) % mod) * i) % mod)) % mod;
                } else {
                    outDegree[i]++;
                    sum[i] = (sum[i] + (((power(7, numNei[i]++) % mod) * j) % mod)) % mod;
                }
            }
        }
    }
    f(i, 0, v) {
        cout << outDegree[i] << " " << sum[i] << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}