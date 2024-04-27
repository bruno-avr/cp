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

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};

void solve() {
    int n, l, a, b;
    cin >> n >> l;
    UnionFind uf(l);
    vector<int> v(l, 0);
    f(i,0,n) {
        cin >> a >> b; a--; b--;
        if (uf.isSameSet(a, b)) {
            if (v[uf.findSet(a)]+1 > uf.sizeOfSet(a)) {
                cout << "SMECE" << endl;
            } else {
                cout << "LADICA" << endl;
                v[uf.findSet(a)]++;
            }
        } else {
            if (v[uf.findSet(a)] + v[uf.findSet(b)] + 1 > (uf.sizeOfSet(a) + uf.sizeOfSet(b))) {
                cout << "SMECE" << endl;
            } else {
                v[uf.findSet(b)] = v[uf.findSet(a)] = v[uf.findSet(a)] + v[uf.findSet(b)] + 1;
                uf.unionSet(a, b);
                cout << "LADICA" << endl;
            }
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}