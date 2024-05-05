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

bool func(vector<int> h, vector<int> w) {
    bool possible = false;
    if (h.size() == 1) return h[0] == w[0];
    if (h[0] == h[1]) {
        vector<int> newH, newW;
        newH.push_back(h[0]);
        newW.push_back(w[0] + w[1]);
        f(i,2,h.size()) {
            newH.push_back(h[i]);
            newW.push_back(w[i]);
        }
        if (func(newH, newW)) possible = true;
    }
    if (w[0] == w[1]) {
        vector<int> newH, newW;
        newH.push_back(h[0] + h[1]);
        newW.push_back(w[0]);
        f(i,2,h.size()) {
            newH.push_back(h[i]);
            newW.push_back(w[i]);
        }
        if (func(newH, newW)) possible = true;
    }
    return possible;
}

void solve() {
    vector<int> h(3), w(3);
    f(i,0,3) {
        cin >> h[i] >> w[i];
    }
    bool possible = false;
    vector<int> v(3);
    iota(all(v), 0);
    do {
        f(i,0,2) {
            f(j,0,2) {
                f(k,0,2) {
                    vector<int> newH(3), newW(3);
                    newH[0] = (i == 0) ? h[v[0]] : w[v[0]];
                    newH[1] = (j == 0) ? h[v[1]] : w[v[1]];
                    newH[2] = (k == 0) ? h[v[2]] : w[v[2]];
                    newW[0] = (i == 0) ? w[v[0]] : h[v[0]];
                    newW[1] = (j == 0) ? w[v[1]] : h[v[1]];
                    newW[2] = (k == 0) ? w[v[2]] : h[v[2]];
                    if (func(newH,newW)) possible = true;
                }
            }
        }
    } while (next_permutation(all(v)));

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}