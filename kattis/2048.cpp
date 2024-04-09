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

void rotate90(vector<vector<int>> &v, int n) {
    f(i,0,n) {
        vector<vector<int>> newV(v);
        // transpose
        f(i,0,4){
            f(j,0,4){
                newV[i][j] = v[j][i];
            }
        }
        // reverse rows
        f(i,0,4){
            reverse(newV[i].begin(), newV[i].end());
        }
        v = newV;
    }
}

void solve() {
    vector<vector<int>> v(4, vector<int>(4));

    f(i,0,4){
        f(j,0,4){
            cin >> v[i][j];
        }
    }

    int side;
    cin >> side;

    // left, up, right, or down
    if (side == 1) rotate90(v, 3);
    if (side == 2) rotate90(v, 2);
    if (side == 3) rotate90(v, 1);

    f(i,0,4){
        f(j,0,3){
            for (int c = j; c < 4 && v[i][j] == 0; c++) {
                f(k,j,3){
                    v[i][k] = v[i][k+1];
                }
                v[i][3] = 0;
            }
            for (int c = j+1; c < 4 && v[i][j+1] == 0; c++) {
                f(k,j+1,3){
                    v[i][k] = v[i][k+1];
                }
                v[i][3] = 0;
            }
            if (v[i][j] == v[i][j+1]) {
                v[i][j] = 2*v[i][j];
                v[i][j+1] = 0;
            }
        }
    }

    if (side == 1) rotate90(v, 1);
    if (side == 2) rotate90(v, 2);
    if (side == 3) rotate90(v, 3);

    f(i,0,4){
        f(j,0,4){
            cout << v[i][j] << (j==3 ? "\n" : " ");
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}