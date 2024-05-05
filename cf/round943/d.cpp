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

void dfs(vector<ll> &v, vector<ll> &a, vector<bool> &visited, ll &maxSum, ll pos, ll currDist, ll currSum, ll k) {
    if (currDist >= k) return;
    visited[pos] = true;
    maxSum = max(currSum + (k-currDist)*a[pos], maxSum);
    ll viz = v[pos];
    if (!visited[viz]) dfs(v,a,visited,maxSum, viz, currDist+1, currSum+a[pos], k);

}

ll getMax(vector<ll> &v, vector<ll> &a, ll pos, ll k) {
    vector<bool> visited(v.size(), false);
    ll maxSum = -1;
    dfs(v, a, visited, maxSum, pos, 0, 0, k);
    return maxSum;
}

void solve() {
    ll n, k, pb, ps;
    cin >> n >> k >> pb >> ps; pb--; ps--;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i]; v[i]--;
    }
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll resB = getMax(v,a,pb,k);
    ll resS = getMax(v,a,ps,k);
    if (resB == resS) cout << "Draw" << endl;
    else if (resB > resS) cout << "Bodya" << endl;
    else cout << "Sasha" << endl;
    
}

int main() {
    optimize;
    ll T;
    cin >> T;

    while (T--) solve();

    return 0;
}