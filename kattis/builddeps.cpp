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

unordered_map<string, unordered_set<string>> graph;
unordered_map<string, bool> visited;
deque<string> res;

void dfs(string &u) {
    visited[u] = true;
    for (auto viz : graph[u]) {
        if (!visited[viz]) dfs(viz);
    }
    res.push_front(u);
}

void solve() {
    int n;
    cin >> n;
    string line, s, s2, str;
    cin.ignore();
    f(i,0,n) {
        getline(cin, line);
        stringstream ss;
        ss << line;
        ss >> s;
        s = s.substr(0, s.size()-1);
        while (ss >> s2) {
            graph[s2].insert(s);
        }
    }
    cin >> str;
    dfs(str);
    for (auto &el : res) {
        cout << el << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}