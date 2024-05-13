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

void dfs(map<int, int> &v, int index) {
    if (v.count(index) == 0) return;
    v[index] = 1;
    dfs(v, index*2);
    dfs(v, index*2+1);
}

void solve() {
    int n, k, a;
    cin >> n >> k;
    set<map<int, int>> s;
    f(i,0,n) {
        map<int, int> v;
        cin >> v[1];
        f(j,1,k) {
            cin >> a;
            int index = 1;
            while (v.count(index)) {
                if (a < v[index]) index <<= 1;
                else index = (index << 1)+1;
            }
            v[index] = a;
        }
        dfs(v, 1);
        s.insert(v);
    };
    cout << s.size() << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}