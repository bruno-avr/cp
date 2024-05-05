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

int cont;
vector<int> res;

void func(vector<int> &colors, int pos, vector<int> &curr, unordered_set<int> &visited, set<pair<int,int>> &sp) {
    if (pos > 1) {
        if (sp.count({curr[pos-1], curr[pos-2]})) {
            return;
        }
    }
    if (pos == colors.size()) {
        if (cont == 0) {
            res.assign(all(curr));
        }
        cont++;
        return;
    }
    for(auto &color : colors) {
        if (visited.count(color) == 0) {
            curr[pos] = color;
            visited.insert(color);
            func(colors, pos+1, curr, visited, sp);
            visited.erase(color);
        }
    }
}

void solve() {
    cont = 0;
    int n, m;
    int id = 0;
    cin >> n;
    vector<string> colors(n);
    vector<int> colorsIdx(n);
    iota(all(colorsIdx), 0);
    unordered_map<string, int> idx;
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
        idx[colors[i]] = id++;
    }
    cin >> m;
    set<pair<int,int>> sp;
    string a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        sp.insert({idx[a],idx[b]});
        sp.insert({idx[b],idx[a]});
    }
    vector<int> curr(n);
    unordered_set<int> visited;
    func(colorsIdx, 0, curr, visited, sp);
    cout << cont << endl;
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << colors[res[i]];
    }
    cout << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}