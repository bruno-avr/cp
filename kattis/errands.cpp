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
#define LSOne(S) ((S)&(-(S)))
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

ld dist[101][101];
ld adj[12][12];
int x, y, n, x1, x2;
ld memo[12][1<<11];
bool memoUsed[12][1<<11];

ld tsp(int curr, int val, int end) {
    ld &res = memo[curr][val];
    if (val == 0) return res = adj[curr][end];
    
    if (memoUsed[curr][val]) return res;
    memoUsed[curr][val] = true;
    res = INF;
    for (int i = val; i > 0; i -= LSOne(i)) {
        int next = __builtin_ctz(i) + 1;
        int nextVal = val - (1<<(next-1));
        res = min(res, tsp(next, nextVal, end) + adj[curr][next]);
    }
    return res;
}

vector<int> resV;
void getRes(int curr, int val) {
    if (val == 0) return;
    
    ld &res = memo[curr][val];
    for (int i = val; i > 0; i -= LSOne(i)) {
        int next = __builtin_ctz(i) + 1;
        int nextVal = val - (1<<(next-1));
        if (abs(memo[next][nextVal] + adj[curr][next] - res) < 0.0000005) {
            resV.push_back(next);
            getRes(next, nextVal);
            break;
        }
    }
    return;
}

void solve() {
    int n;
    cin >> n;
    string name;
    unordered_map<string, int> id;
    int x, y, idx = 0;
    vector<ld> pointX(n);
    vector<ld> pointY(n);
    f(i,0,n) {
        cin >> name >> pointX[i] >> pointY[i];
        id[name] = idx++;
    }
    f(i,0,n) f(j,0,n) {
        ld linex = abs(pointX[i] - pointX[j]);
        ld liney = abs(pointY[i] - pointY[j]);
        dist[i][j] = sqrt(linex*linex+liney*liney);
    }

    string line;
    cin.ignore();
    while (getline(cin, line)) {
        f(i,0,12)
            f(j,0,(1<<11))
                memoUsed[i][j] = 0;
        stringstream ss;
        ss << line;
        vector<int> v;
        vector<string> vname;
        v.push_back(id["work"]);
        vname.push_back("work");
        while (ss >> name) {
            v.push_back(id[name]);
            vname.push_back(name);
        }
        v.push_back(id["home"]);
        vname.push_back("home");
        f(i,0,v.size()) f(j,0,v.size()) {
            adj[i][j] = dist[v[i]][v[j]];
        }
        ld res = tsp(0, (1<<(v.size()-2))-1, v.size()-1);
        resV.clear();
        getRes(0, (1<<(v.size()-2))-1);
        for (int i = 0; i < resV.size(); i++) {
            if (i != 0) cout << " ";
            cout << vname[resV[i]];
        }
        cout << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}