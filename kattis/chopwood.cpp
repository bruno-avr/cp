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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> qnt(n+2, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        qnt[v[i]]++;
    }
    
    if (v.back() != n+1) {
        cout << "Error" << endl;
        return;
    }

    set<int> out;
    for (int i = 1; i <= n+1; i++) {
        if(!qnt[i]) {
            out.insert(i);
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (out.empty()) {
            cout << "Error" << endl;
            return;
        }
        res.push_back(*out.begin());
        out.erase(out.begin());
        qnt[v[i]]--;
        if (!qnt[v[i]]) out.insert(v[i]);
    }
    for(auto el : res) {
        cout << el << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}