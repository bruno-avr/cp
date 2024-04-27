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
    int k, days, m, u, v, d, z, a, b, c;
    cin >> k >> days >> m;
    vector<vector<vector<pair<int,int>>>> schedule(days, vector<vector<pair<int,int>>>(k));
    vector<vector<int>> onAirport(days+1, vector<int>(k));

    f(i,0,m) {
        cin >> u >> v >> d >> z; u--; v--; d--;
        schedule[d][u].push_back({v, z});
    }

    f(i,0,k*days) {
        cin >> a >> b >> c; a--; b--;
        onAirport[b][a] = c;
    }

    f(i,0,days) {
        f(j,0,k) {
            if (i > 0) {
                onAirport[i][j] += onAirport[i-1][j];
            }
            for (int viz = 0; viz < schedule[i][j].size(); viz++) {
                auto curr = schedule[i][j][viz];
                if (onAirport[i][j] < curr.second) {
                    cout << "suboptimal" << endl;
                    return;
                }
                onAirport[i+1][curr.first] += curr.second;
                onAirport[i][j] -= curr.second;
            }
        }
    }
    cout << "optimal" << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}