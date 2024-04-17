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
    int n, op, infectionLevel;
    string catName;
    cin >> n;
    map<int, priority_queue<pair<int, string>>> state;
    map<string, int> infectionLevels;
    unordered_map<string, int> entryTime;
    int numCats = 0;
    f(i,0,n) {
        cin >> op;
        if (op == 0) {
            numCats++;
            cin >> catName >> infectionLevel;
            infectionLevels[catName] = infectionLevel;
            state[infectionLevel].push({-i, catName});
            entryTime[catName] = -i;
        } else if (op == 1) {
            cin >> catName >> infectionLevel;
            infectionLevels[catName] += infectionLevel;
            state[infectionLevels[catName]].push({entryTime[catName], catName});
        } else if (op == 2) {
            cin >> catName;
            infectionLevels[catName] = -1;
            numCats--;
        } else {
            if (!numCats) cout << "The clinic is empty" << endl;
            else {
                while(true) {
                    auto &[e, cat] = (*(state.rbegin())).second.top();
                    if ((*(state.rbegin())).first == infectionLevels[cat]) {
                        cout << cat << endl;
                        break;
                    } else {
                        state[(*(state.rbegin())).first].pop();
                        if (!state[(*(state.rbegin())).first].size()) {
                            state.erase((*(state.rbegin())).first);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}