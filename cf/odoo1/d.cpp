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

bool isPossible(vector<int> &v, int m, int t) {
    priority_queue<int> pq;
    for (int i = 0; i < m; i++) {
        pq.push(t);
    }
    for (int i = 0; i < v.size(); i++) {
        int thisV = pq.top();
        if (v[i] > thisV) {
            return false;
        }
        pq.pop();
        pq.push(thisV-v[i]);
    }
    return true;
}

int binarySearch(vector<int> &v, int l, int r, int t) {
    int res = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        if (isPossible(v, m, t)) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
 
    return res;
}

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    int maxN = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        maxN = max(v[i], maxN);
    }
    if (maxN > t) {
        cout << -1 << endl;
        return;
    }
    cout << binarySearch(v, 1, n, t) << endl;
    
}

int main() {
    optimize;
    int T = 1;

    while (T--) solve();

    return 0;
}