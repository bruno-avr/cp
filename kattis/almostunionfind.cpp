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

typedef vector<ll> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize, sum;                           // vi p is the key part
  ll numSets, curr;
public:
  UnionFind(ll N, ll curr_) {
    p.assign(N, 0); for (ll i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    sum.assign(N, 0);                        // optional feature
    iota(all(sum), 1);
    numSets = N;                                 // optional feature
    curr = curr_;
  }

  ll findSet(ll i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(ll i, ll j) { return findSet(i) == findSet(j); }

  ll numDisjollSets() { return numSets; }      // optional
  ll sizeOfSet(ll i) { return setSize[findSet(i)]; } // optional
  ll getSum(ll i) { return sum[findSet(i)]; } // optional

  void unionSet(ll i, ll j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    ll x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    sum[y] += sum[x];
    --numSets;                                   // a union reduces numSets
  }

  ll move(ll i, ll j, ll iV) {
    ll x = findSet(i);
    setSize[x]--;
    sum[curr] = iV;
    sum[x] -= iV;
    unionSet(j, curr);
    return curr++;
  }
};

void solve() {
    ll n, m, p, q;
    while (cin >> n >> m) {
        UnionFind uf(n + m, n);
        vector<ll> v(n);
        iota(all(v), 0);
        ll op;
        f(i,0,m) {
            cin >> op >> p; p--;
            if (op == 1) {
                cin >> q; q--;
                uf.unionSet(v[p], v[q]);
            } else if (op == 2) {
                cin >> q; q--;
                v[p] = uf.move(v[p], v[q], p+1);
            } else {
                cout << uf.sizeOfSet(v[p]) << " " << uf.getSum(v[p]) << endl;
            }
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}