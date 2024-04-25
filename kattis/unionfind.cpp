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

class UnionFind {
    private:
        vector<int> v;
        vector<int> size;
    public:
        UnionFind(int n) {
            v.assign(n, 0);
            iota(all(v), 0);
            size.assign(n, 1);
        }

        int find(int i) {
            int res = i;
            if (v[res] == res) return res;
            return v[res] = find(v[res]);
        }

        void join(int i, int j) {
            int a1 = find(i), a2 = find(j);
            if (a1 == a2) return;
            if (size[a1] < size[a2]) swap(a1, a2);
            v[a2] = a1;
            if (size[a1] == size[a2]) size[a1]++;
        }
};

void solve() {
    int n, q, a, b;
    cin >> n >> q;
    string op;
    UnionFind uf(n);
    while (q--) {
        cin >> op >> a >> b;
        if (op == "=") {
            uf.join(a, b);
        } else {
            if (uf.find(a) == uf.find(b)) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}