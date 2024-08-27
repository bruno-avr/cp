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
    int m, n; cin >> m >> n;

    const int max = 260;
    vector<vector<int>> adj(260, vector<int>(260, 0));

    char a, b;
    f(i,0,m) {
        cin >> a >> b;
        adj[a][b] = 1;
    }
    
    f(k,0,max) f(i,0,max) f(j,0,max) {
        adj[i][j] |= adj[i][k] & adj[k][j];
    }
    f(i,0,max) adj[i][i] = 1;

    string w1, w2;
    f(i,0,n) {
        cin >> w1 >> w2;
        if (w1.size() != w2.size()) {
            cout << "no" << endl;
            continue;
        }

        bool check = 0;
        for (int i = 0; i < w1.size(); i++) {
            if (adj[w1[i]][w2[i]] == 0) {
                cout << "no" << endl;
                check = 1;
                break;
            }
        }
        if (check) continue;
        cout << "yes" << endl;
    }

}

int main() {
    optimize;
    solve();

    return 0;
}