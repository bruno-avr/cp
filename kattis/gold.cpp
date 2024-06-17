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

int floodfill(int r, int c) {  // returns the size of CC
  if ((r < 0) || (r >= R) || (c < 0) || (c >= C)) return 0; // outside grid
  if (grid[r][c] != '.' and grid[r][c] != 'G') return 0; // does not have color c1
  int ans = (grid[r][c] == 'G') ? 1 : 0;         // (r, c) has color c1
  grid[r][c] = '#';                               // to avoid cycling
  for (int d = 0; d < 4; ++d) {
    int newR = r+dr[d], newC = c+dc[d];
    if ((newR < 0) || (newR >= R) || (newC < 0) || (newC >= C)) continue;
    if (grid[newR][newC] == 'T') return ans;
  }
  for (int d = 0; d < 4; ++d)
    ans += floodfill(r+dr[d], c+dc[d]);  // the code is neat as
  return ans;                                    // we use dr[] and dc[]
}

void solve(int c) {
    string s[R];
    f(i,0,R) cin >> s[i];
    int px, py;
    f(i,0,R) f(j,0,C) {
        grid[i][j] = s[i][j];
        if (grid[i][j] == 'P') {
            px = i; py = j;
            grid[i][j] = '.';
        }
    }
    int res = floodfill(px,py);
    // cout << px << " " << py << endl;
    cout << res << endl;
}

int main() {
    optimize;
    int c = 1;
    while (cin >> C >> R) solve(c++);

    return 0;
}