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
    long double l, w, r, x , y;
    cin >> l >> w >> n >> r;
    vector<pair<long double, long double>> walls(4);
    walls[0] = {-l/2, 0};
    walls[1] = {l/2, 0};
    walls[2] = {0, -w/2};
    walls[3] = {0, w/2};
    vector<set<int>> v(n);
    f(i,0,n) {
        cin >> x >> y;
        f(j,0,4) {
            long double dist = sqrtl(powl(abs(x - walls[j].first), 2) + powl(abs(y - walls[j].second), 2)) - 0.000005l;
            if (dist <= r) {
                v[i].insert(j);
            }
        }
    }
    for (auto &el : v) {
        if (el.size() == 4) {
            cout << 1 << endl;
            return;
        }
    }
    set<set<int>> ss;
    for (auto el : v) {
        if (el.size()) {
            ss.insert(el);
        }
    }
    vector<set<int>> vs(all(ss));

    int minN = 100;
    int subs = (1<<vs.size()) - 1;
    for (int i = subs; i; i = (i-1)&subs) {
        set<int> bs;
        int cont = 0;
        for (int j = 0; j < vs.size(); j++) {
            if (i & (1 << j)) {
                cont++;
                for (auto el : vs[j]) {
                    bs.insert(el);
                }
            }
        }
        if (bs.size() == 4) {
            minN = min(minN, cont);
        }
    }


    if (minN == 100) {
        cout << "Impossible" << endl;
        return;
    }
    cout << minN << endl;
    
}

int main() {
    optimize;
    solve();

    return 0;
}