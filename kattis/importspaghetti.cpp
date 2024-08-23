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

map<string, int> id;
map<int, string> dict;
int idx = 0;

int getId(string &s) {
    if (id.count(s) == 0) {
        dict[idx] = s;
        id[s] = idx++;
    }
    return id[s];
}

void printPath(int i, int j, vector<vector<int>> &p) {
    if (p[i][j] == i) {
        cout << dict[j] << endl;
        return;
    }
    printPath(i, p[i][j], p);
    cout << dict[j] << endl;
}

void solve() {
    int n; cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, INF));
    vector<vector<int>> p(n, vector<int>(n, INF));
    string s;
    f(i,0,n) {
        f(j,0,n) p[i][j] = i;
        cin >> s;
    }
    string line;
    f(i,0,n) {
        int k;
        cin >> s >> k;
        cin.ignore();
        f(j,0,k) {
            stringstream ss;
            getline(cin, line);
            ss << line;
            string s2;
            ss >> s2;
            while (ss >> s2) {
                if (s2.back() == ',') {
                    s2 = s2.substr(0, s2.size()-1);
                }
                adj[getId(s)][getId(s2)] = 1;
            }
        }
    }
    f(k,0,n) f(i,0,n) f(j,0,n) {
        if (adj[i][k] + adj[k][j] < adj[i][j]) {
            adj[i][j] = adj[i][k] + adj[k][j];
            p[i][j] = p[k][j];
        }
    }
    int res = INF;
    int index;
    f(i,0,n) {
        // cout << adj[i][i] << endl;
        if (adj[i][i] < res) {
            res = adj[i][i];
            index = i;
        }
    }

    if (res == INF) {
        cout << "SHIP IT" << endl;
    } else {
        printPath(index, index, p);
    }
}

int main() {
    optimize;
    solve();

    return 0;
}