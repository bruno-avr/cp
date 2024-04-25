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
    int n, k;
    cin >> n >> k;
    unordered_map<int, unordered_map<int, int>> um(2*n);
    for (int i = 0; i < n; i++) um[i] = unordered_map<int, int>(2*(n-i));
    um[0][0] = k-1;
    int startCol = 0;
    for (int row = 0; row < n; row++) {
      for (int col = startCol; col < (n-row); col++) {
            if (col > 0) um[row][col] += um[row][col-1] / 2;
            if (row > 0) um[row][col] += (um[row-1][col] + 1) / 2;
            if (col > 0) if (um[row][col] == 0 && um[row][col-1] == 0) break;
            if (row > 0) if (um[row][col] == 1 && um[row-1][col] == 1) startCol++;
        }
    }
    
    int col = 0, row = 0;
    while (row != n-1-col) {
        if (um[row][col] % 2 == 0) { // down
            row++;
        } else { // right
            col++;
        }
    }
    cout << col << endl;

}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}