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

int func(int lab, int n, int m, vector<int> v, vector<int> nin, vector<vector<int>> graph) {
    set<pair<int,int>> pq;
    for (int i = 0; i < n; i++) {
        if (nin[i] == 0) {
            pq.insert({v[i], i});
        }
    }
    int res = 0;
    while(!pq.empty()) {
        pair<int,int> el;
        if (lab == 1) {
            el = *(pq.begin());
            pq.erase(pq.begin());
        } else {
            auto it = pq.end();
            it--;
            el = *it;
            pq.erase(it);
        }
        // cout << lab << " " << el.first << " " << el.second << endl;
        if (lab != el.first) {
            // cout << "change" <<el.first<< endl;
            res++;
            lab = el.first;
        }
        for (auto viz : graph[el.second]) {
            nin[viz]--;
            if (nin[viz] == 0) {
                pq.insert({v[viz], viz});
            }
        }
    }
    return res;
}

void solve() {
    int n, m, a, b;
    cin >> n >> m;
    vector<int> v(n);
    f(i,0,n) cin >> v[i];
    vector<vector<int>> graph(n);
    vector<int> nin(n, 0);
    f(i,0,m) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        nin[b]++;
    }
    int res = min(func(1,n,m,v,nin,graph), func(2,n,m,v,nin,graph));
    cout << res << endl;
}

int main() {
    optimize;
    int T; cin >> T;
    while (T--) solve();

    return 0;
}