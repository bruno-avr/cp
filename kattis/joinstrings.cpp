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

void calc(vector<string> &v, vector<deque<int>> &order, string &res, int curr) {
    res += v[curr];
    for (int el : order[curr]) {
        calc(v, order, res, el);
    }
}

void solve() {
    int n, a, b, start = 0;
    cin >> n;
    vector<string> v(n);
    f(i,0,n) {
        cin >> v[i];
    }
    vector<deque<int>> order(n);
    f(i,0,n-1) {
        cin >> a >> b; a--; b--;
        order[a].push_back(b);
        start = a;
    }
    string res = "";
    calc(v, order, res, start);
    cout << res << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}