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

int curr;

bool cmp (const vector<string> &a, const vector<string> &b) {
    return a[curr] < b[curr];
}

void solve() {
    string line;
    unordered_map<string, int> um;
    vector<string> names;
    getline(cin, line);
    line += " ";
    int cont = 0, currPos = 0;
    while (true) {
        int pos = line.find(" ", currPos);
        if (pos >= line.size()) break;
        names.push_back(line.substr(currPos, pos-currPos));
        um[names.back()] = cont++;
        currPos = pos+1;
    }
    
    int n, m;
    cin >> n;
    vector<vector<string>> vvs(n, vector<string>(cont));
    for (int i = 0; i < n; i++) {
        f(j,0,cont) {
            cin >> vvs[i][j];
        }
    }

    cin >> m;
    string aux;
    bool first = true;
    while (m--) {
        if (first) first = false;
        else cout << endl;
        cin >> aux;
        curr = um[aux];
        stable_sort(all(vvs), cmp);

        for (int i = 0; i < cont; i++) {
            cout << names[i] << (i == cont-1 ? "\n" : " ");
        }
        for (int i = 0; i < n; i++) {
            f(j,0,cont) {
                cout << vvs[i][j] << (j == cont-1 ? "\n" : " ");
            }
        }
    }

}

int main() {
    optimize;
    solve();

    return 0;
}