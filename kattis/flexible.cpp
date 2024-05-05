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
    int w, p;
    cin >> w >> p;
    deque<int> v(p);
    f(i,0,p) {
        cin >> v[i];
    }
    v.push_front(0);
    v.push_back(w);
    set<int> res;
    f(i,0,v.size()) {
        f(j,i+1,v.size()) {
            res.insert(abs(v[i] - v[j]));
        }
    }
    int first = true;
    for (auto el : res) {
        if (first) first = false;
        else cout << " ";
        cout << el;
    }
    cout << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}