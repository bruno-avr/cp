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

vector<int> prices[54];
vector<int> numTickets[54];
int memo[54][301];
int n, w;

int dp(int week, int seatsLeft) {
    if (week == w) return 0;
    int &res = memo[week][seatsLeft];
    if (res != -1) return res;
    res = 0;
    for (int i = 0; i < prices[week].size(); i++) {
        int j = min(seatsLeft, numTickets[week][i]);
        res = max(res, dp(week+1, seatsLeft - j) + j*prices[week][i]);
    }
    return res;
}

void solve() {
    memset(memo, -1, sizeof memo);
    cin >> n >> w; w++;
    int k;
    for (int i = 0; i < w; i++) {
        cin >> k;
        prices[i].assign(k, 0);
        numTickets[i].assign(k, 0);
        f(j,0,k) cin >> prices[i][j];
        f(j,0,k) cin >> numTickets[i][j];
    }
    int res = dp(0, n);
    cout << res << endl;
    for (int i = 0; i < prices[0].size(); i++) {
        int j = min(n, numTickets[0][i]);
        if (dp(1, n - j) + j*prices[0][i] == memo[0][n]) {
            cout << prices[0][i] << endl;
            return;
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}