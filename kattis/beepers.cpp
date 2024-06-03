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

int x, y, n, x1, x2;
int adj[11][11];
int memo[11][1<<10];

int tsp(int curr, int val) {
    int &res = memo[curr][val];
    if (val == 0) return res = adj[curr][0];
    
    if (res != -1) return res;
    res = INF;
    for (int i = val; i > 0; i -= LSOne(i)) {
        int next = __builtin_ctz(i) + 1;
        int nextVal = val - (1<<(next-1));
        res = min(res, tsp(next, nextVal) + adj[curr][next]);
    }
    return res;
}

void print(int curr, int val) {
    if (val == 0) {
        cout << curr << " - " << 0 << " = " << adj[curr][0] << endl;
        return;
    }
    
    int &res = memo[curr][val];
    for (int i = val; i > 0; i -= LSOne(i)) {
        int next = __builtin_ctz(i) + 1;
        int nextVal = val - (1<<(next-1));
        if (memo[next][nextVal] + adj[curr][next] == res) {
            cout << curr << " - " << next << " = " << adj[curr][next] << " " << nextVal << endl;
            print(next, nextVal);
            break;
        }
    }
    return;
}

void solve() {
    memset(memo, -1, sizeof memo);
    cin >> x >> y;
    cin >> x1 >> x2;
    cin >> n;
    vector<int> vx(n+1), vy(n+1);
    vx[0] = x1;
    vy[0] = x2;
    f(i,1,n+1) {
        cin >> vx[i] >> vy[i];
    }
    for (int i = 0; i < vx.size(); i++)
        for (int j = 0; j < vx.size(); j++) {
            adj[i][j] = abs(vx[i] - vx[j]) + abs(vy[i] - vy[j]);
            // cout << adj[i][j] << " ";
        }
    
    cout << tsp(0, (1<<n)-1) << endl;
    // print(0, (1<<n)-1);
    // cout << memo[1][14] + adj[0][1] << endl;
    // cout << memo[2][13] + adj[0][2] << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}