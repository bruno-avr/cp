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
#define LSOne(S) ((S)&(-(S)))
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int n, m;

int adj[20][20];
int memo1[20][1<<18];
int memo2[20][1<<18];

int tsp1(int curr, int val) {
    if (val == 0) return adj[curr][n-1];
    int &res = memo1[curr][val];
    
    if (res != -1) return res;
    res = INF;
    for (int i = val; i > 0; i -= LSOne(i)) {
        int next = __builtin_ctz(i) + 1;
        int nextVal = val - (1<<(next-1));
        if (adj[curr][next] != -1) {
            res = min(res, tsp1(next, nextVal) + adj[curr][next]);
        }
    }
    return res;
}

int tsp2(int curr, int val) {
    if (val == 0) return adj[curr][0];
    int &res = memo2[curr][val];
    
    if (res != -1) return res;
    res = INF;
    for (int i = val; i > 0; i -= LSOne(i)) {
        int next = __builtin_ctz(i) + 1;
        int nextVal = val - (1<<(next-1));
        if (adj[curr][next] != -1) {
            res = min(res, tsp2(next, nextVal) + adj[curr][next]);
        }
    }
    return res;
}

void floydWarshall(){
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (adj[i][j] > (adj[i][k] + adj[k][j])
                    && (adj[k][j] != INF
                        && adj[i][k] != INF))
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }
}

void solve(int c) {
    int u, v, t;
    memset(memo1, -1, sizeof memo1);
    memset(memo2, -1, sizeof memo2);
    f(i,0,n)
        f(j,0,n)
            adj[i][j] = INF;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> t;
        adj[u][v] = t;
        adj[v][u] = t;
    }
    floydWarshall();

    int res = INF;
    
    if (n == 3) {
        res = adj[0][1] + adj[1][2] + adj[2][1] + adj[1][0];
    } else {
        for (int i = 0; i < (1<<(n-2)); i++) {
            if (__builtin_popcount(i) != (n-2)/2) continue;
            for (int j = 0; j < n-2; j++) {
                for (int k = 0; k < n-2; k++) {
                    if (((1<<j)&i) == 0) continue;
                    if (((1<<k)&i) == 0) continue;
                    // cout << i << " " << j << " " << k << endl;
                    // cout << "a: " << tsp2(j+1, i-(1<<j)) << endl;
                    // cout << "b: " << tsp1(j+1, (1<<(n-2))-1-i) << endl;
                    // cout << "c: " << tsp1(k+1, (1<<(n-2))-1-i) << endl;
                    // cout << "d: " << tsp2(k+1, i-(1<<k)) << endl;
                    res = min(res, (
                        tsp2(j+1, i-(1<<j)) +
                        tsp1(j+1, (1<<(n-2))-1-i) +
                        tsp1(k+1, i-(1<<k)) +
                        tsp2(k+1, (1<<(n-2))-1-i)
                    ));
                }
            }
        }
    }

    cout << "Case " << c << ": " << res << endl;


    // path.clear();
    // getPath(0, (1<<(n-2))-1);

    // int dist1 = adj[n-1][path[0]];
    // int dist2 = adj[0][path.back()];

    // int res = resTsp;
    // res += dist1;
    // res += resTsp-adj[0][path[0]]-adj[path.back()][n-1];
    // res += dist2;
}

int main() {
    optimize;
    int c = 0;
    while (cin >> n >> m) solve(++c);

    return 0;
}