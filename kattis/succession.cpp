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

pair<ll, ll> g[200];
unordered_map<string, ll> id;
unordered_set<ll> isClaimant;
ll idx = 0;
ll memo[200];
ll getId(string &s) {
    if (!id.count(s)) {
        id[s] = idx++;
    }
    return id[s];
}

ll blood(ll u) {
    ll &ans = memo[u];
    if (ans != -1) return ans;
    if (g[u].first == -1) return 0;
    ll b1 = blood(g[u].first);
    ll b2 = blood(g[u].second);
    return ans = blood(g[u].first)/2 + blood(g[u].second)/2;
}

void solve() {
    ll n, m;
    string founder, child, p1, p2, claimant;
    ll founderI, childI, p1I, p2I, claimantI;
    cin >> n >> m;
    cin >> founder;
    founderI = getId(founder);
    f(i,0,200) g[i] = {-1, -1};
    f(i,0,n) {
        cin >> child >> p1 >> p2;
        childI = getId(child);
        p1I = getId(p1);
        p2I = getId(p2);
        g[childI] = {p1I, p2I};
    }
    memset(memo, -1, sizeof memo);
    memo[0] = 1ll<<60;
    priority_queue<pair<ll,string>> pq;
    f(i,0,m) {
        cin >> claimant;
        claimantI = getId(claimant);
        pq.push({blood(claimantI), claimant});
    }
    cout << pq.top().second << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}