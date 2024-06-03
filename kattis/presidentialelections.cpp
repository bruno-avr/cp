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

int s, needed;
vector<int> weights;
vector<int> values;

// unordered_map<int, int> memo[2018];

// int knapsack(int idx, int weight) {
//     if (idx == values.size()) return 0;

//     if (memo[idx].count(weight)) return memo[idx][weight];
//     int &res = memo[idx][weight];

//     if (weight-weights[idx] >= 0) return res = max(
//         knapsack(idx+1, weight),
//         knapsack(idx+1, weight-weights[idx]) + values[idx]
//     );
//     return res = knapsack(idx+1, weight);
// }

// bool p(int m) {
//     for (int i = 0; i < 2018; i++) memo[i].clear();
//     int res = knapsack(0, m);
//     return res >= needed;
// }

// int bs(int l, int r) {
//     while (l < r) {
//         int m = l+(r-l)/2;
//         (p(m)) ? r = m : l = m+1;
//     }
//     if (p(l)) return l;
//     return -1;
// }

int memo[2018][2018];
int dp(int index, int currNeeded) {
    if (currNeeded <= 0) return 0;
    if (index == weights.size()) return INF;
    if (memo[index][currNeeded] != -1) return memo[index][currNeeded];
    int &res = memo[index][currNeeded];
    res = min(dp(index+1, currNeeded), dp(index+1,currNeeded - values[index]) + weights[index]);
    return res;
}

void solve() {
    cin >> s;
    int totalD = 0;
    int currD = 0;
    int totalU = 0;
    f(i,0,s) {
        int d, c, f, u;
        cin >> d >> c >> f >> u;
        totalD += d;

        int totalVotes = c+f+u;
        int remaining = max(0, (totalVotes/2+1)-c);
        if (remaining > 0) {
            if (remaining <= u) {
                totalU += u;
                weights.push_back(remaining);
                values.push_back(d);
            }
        } else {
            currD += d;
        }
    }
    needed = totalD/2+1;
    needed -= currD;
    if (needed <= 0) {
        cout << 0 << endl;
        return;
    }

    memset(memo, -1, sizeof(memo));
    int res = dp(0, needed);
    if (res == INF) {
        cout << "impossible" << endl;
    } else {
        cout << res << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}