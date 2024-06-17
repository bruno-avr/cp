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

int n;
unordered_map<string, unordered_set<string>> graph;
unordered_map<string, bool> visited;
string s, s2, line;
vector<string> res;
vector<string> currRes;

void dfs(string &str) {
    visited[str] = true;
    currRes.push_back(str);
    if (str == s2) {
        res = currRes;
    }

    for (auto viz : graph[str]) {
        if (!visited[viz]) {
            dfs(viz);
        }
    }
    currRes.pop_back();
}

void solve() {
    cin >> n;
    cin.ignore();
    f(i,0,n) {
        getline(cin, line);
        stringstream ss;
        ss << line;
        ss >> s;
        while (ss >> s2) {
            graph[s].insert(s2);
            graph[s2].insert(s);
        }
    }
    cin >> s >> s2;
    dfs(s);
    if (res.size()) {
        for (int i = 0; i < res.size(); i++) {
            if (i > 0) cout << " ";
            cout << res[i];
        }
        cout << endl;
    } else {
        cout << "no route found" << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}