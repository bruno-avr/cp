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

void solve(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<pair<int,int>> stacks;
    vector<int> parent(n, -1);
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(all(stacks), make_pair(v[i], 0));
        if (it != stacks.begin()) {
            auto it2 = it;
            it2--;
            parent[i] = (*it2).second;
        }
        if (it == stacks.end()) stacks.push_back({v[i], i});
        else {
            (*it) = {v[i], i};
        }
    }
    cout << stacks.size();
    int curr = stacks.back().second;
    vector<int> res;
    while (curr != -1) {
        res.push_back(v[curr]);
        curr = parent[curr];
    }
    reverse(all(res));
    for (auto &el : res) cout << " " << el;
    cout << endl;
    
}

int main() {
    optimize;
    int n;
    while(cin >> n, n) solve(n);

    return 0;
}