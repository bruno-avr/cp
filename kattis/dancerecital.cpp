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

void solve() {
    int r;
    cin >> r;
    vector<int> v(r);
    string s;
    vector<unordered_set<int>> pos(r);
    vector<vector<int>> diffBetPos(r, vector<int>(r));
    f(i,0,r) {
        cin >> s;
        f(j,0,s.size()) {
            pos[i].insert(s[j]-'A');
        }
    }
    f(i,0,r) {
        f(j,i+1,r) {
            int count = 0;
            for (auto &el : pos[i]) {
                if (pos[j].count(el)) count++;
            }
            diffBetPos[i][j] = count;
            diffBetPos[j][i] = count;
        }
    }
    iota(all(v),0);
    int minN = 1e9;
    do {
        int count = 0;
        f(i,1,r) {
            count += diffBetPos[v[i]][v[i-1]];
        }
        minN = min(minN, count);
    } while (next_permutation(all(v)));

    cout << minN << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}