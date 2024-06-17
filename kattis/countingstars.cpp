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

char line[150], grid[150][150];
int R, C;

int dr[] = { 0, 0, 1, -1 };            // the order is:
int dc[] = { 1, -1, 0, 0 };            // S/SE/E/NE/N/NW/W/SW

int floodfill(int r, int c, char c1, char c2) {  // returns the size of CC
  if ((r < 0) || (r >= R) || (c < 0) || (c >= C)) return 0; // outside grid
  if (grid[r][c] != c1) return 0;                // does not have color c1
  int ans = 1;                                   // (r, c) has color c1
  grid[r][c] = c2;                               // to avoid cycling
  for (int d = 0; d < 4; ++d)
    ans += floodfill(r+dr[d], c+dc[d], c1, c2);  // the code is neat as
  return ans;                                    // we use dr[] and dc[]
}

void solve(int c) {
    string s[R];
    int res = 0;
    f(i,0,R) cin >> s[i];
    f(i,0,R) f(j,0,C) grid[i][j] = s[i][j];
    f(i,0,R) f(j,0,C) {
        if (floodfill(i,j,'-','#')) res++;
    }
    cout << "Case " << c << ": " << res << endl;
}

int main() {
    optimize;
    int c = 1;
    while (cin >> R >> C) solve(c++);

    return 0;
}