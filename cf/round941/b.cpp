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

#define f(i,s,e) for(int i=s;i<e;i++)
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

bool check(vector<vector<bool>> &v, int n, int m) {
    int minI = -1, maxI = -1, minJ = -1, maxJ = -1;
    f(i,0,n) {
        f(j,0,m) {
            if (v[i][j]) {
                if (minI == -1) {
                    minI = i;
                    maxI = i;
                    minJ = j;
                    maxJ = j;
                } else {
                    minI = min(minI, i);
                    maxI = max(i, maxI);
                    minJ = min(minJ, j);
                    maxJ = max(j, maxJ);
                }
            }
        }
    }
    if (minI == 0 && minJ == 0 && maxI == n-1 && maxJ == m-1) return true;
    return false;
}

void solve() {
    int n, m;
    string s;
    cin >> n >> m;
    vector<vector<bool>> v(n, vector<bool>(m));
    f(i,0,n) {
        cin >> s;
        f(j,0,m) {
            v[i][j] = s[j] == 'B';
        }
    }
    if (check(v, n, m)) {
        cout << "YES" << endl;
        return;
    }
    f(i,0,n) {
        f(j,0,m) {
            v[i][j] = !v[i][j];
        }
    }
    if (check(v, n, m)) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}