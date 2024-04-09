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
    int n, k, a;
    cin >> n >> k;
    deque<int> cmds;
    string s;
    int curr = 0;
    for (int i = 0; i < k; i++) {
        cin >> s;
        if (s == "undo") {
            cin >> a;
            f(j,0,a) {
                cmds.pop_back();
            }
        } else {
            cmds.push_back(stoi(s));
        }
    }
    while (!cmds.empty()) {
        int cmd = cmds.front(); cmds.pop_front();
        curr = (curr + cmd + 10010*n) % n;
    }
    cout << curr << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}