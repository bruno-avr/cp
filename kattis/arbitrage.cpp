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

int n, idx;

unordered_map<string, int> id;
ld adj[201][201];

int getId(string &s) {
    if (id.count(s) == 0) return id[s] = idx++;
    return id[s];
}

pair<ld,ld> getR(string ratio) {
    int curr = 0;
    string s1 = "", s2 = "";
    for (char c : ratio) {
        if (c == ':') curr = 1;
        else if (curr == 0) s1 += c;
        else s2 += c;
    }
    return {stoi(s1), stoi(s2)};
}

void solve() {
    idx = 0;
    id.clear();
    string code1, code2, ratio;
    f(i,0,n) cin >> code1;
    int r; cin >> r;
    f(i,0,n) f(j,0,n) {
        adj[i][j] = 0;
    }
    f(i,0,r) {
        cin >> code1 >> code2 >> ratio;
        auto [r1, r2] = getR(ratio);
        // cout << r1 << " " << r2 << endl;
        adj[getId(code1)][getId(code2)] = r2/r1;
    }
    f(i,0,n) adj[i][i] = 1;

    f(k,0,n) f(i,0,n) f(j,0,n) {
        adj[i][j] = max(adj[i][j], adj[i][k] * adj[k][j]);
        if (i == j and adj[i][i] > 1.00000005) {
            cout << "Arbitrage" << endl;
            return;
        }
    }
    cout << "Ok" << endl;
}

int main() {
    optimize;
    while(cin >> n, n) solve();

    return 0;
}