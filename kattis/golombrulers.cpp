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
    string line;
    while (getline(cin, line)) {
        stringstream ss;
        ss << line;
        int a;
        vector<int> v;
        int maxN = -1;
        while (ss >> a) {
            maxN = max(maxN,a);
            v.push_back(a);
        }
        sort(all(v));
        reverse(all(v));
        unordered_set<int> marks;
        bool possible = true;
        f(i,0,v.size()) {
            f(j,i+1,v.size()) {
                int el = v[i] - v[j];
                if (marks.count(el)) {
                    possible = false;
                } else marks.insert(el);
            }
        }
        if (!possible) cout << "not a ruler" << endl;
        else {
            if (marks.size() == maxN) {
                cout << "perfect" << endl;
            } else {
                cout << "missing";
                for (int i = 1; i <= maxN; i++) {
                    if (marks.count(i) == 0) {
                        cout << " " << i;
                    }
                }
                cout << endl;
            }
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}