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
    int n, m, q, pos, capacity, virusId, capacityAgainst;
    cin >> n >> m >> q;
    string moduleName;
    unordered_map<string, int> capacities;
    vector<pair<int, string>> modulePos(n);
    map<string, bool> moduleSurvives;
    f(i,0,n) {
        cin >> moduleName >> capacity >> pos;
        capacities[moduleName] = capacity;
        modulePos[i] = {pos, moduleName};
        moduleSurvives[moduleName] = true;
    }
    sort(all(modulePos));

    vector<int> virusPos(m);
    vector<bool> isDead(m, false);
    f(i,0,m) {
        cin >> virusId >> pos;
        virusPos[virusId-1] = pos;
    }
    
    unordered_map<string, set<pair<int,pair<int,int>>>> virusPerModule;
    f(i,0,q) {
        cin >> virusId >> moduleName >> capacityAgainst; virusId--;
        virusPerModule[moduleName].insert({virusPos[virusId], {virusId, capacityAgainst}});
    }

    for (int i = n-1; i >= 0; i--) {
        // cout << modulePos[i].second << endl;
        for (auto v : virusPerModule[modulePos[i].second]) {
            if (v.first < modulePos[i].first) continue;
            auto &[virusId, capacityAgainst] = v.second;
            if (isDead[virusId]) continue;
            if (capacityAgainst < capacities[modulePos[i].second]) {
                capacities[modulePos[i].second] -= capacityAgainst;
                isDead[virusId] = true;
                continue;
            }
            if (capacityAgainst == capacities[modulePos[i].second]) {
                isDead[virusId] = true;
            }
            moduleSurvives[modulePos[i].second] = false;
            break;
        }
    }

    vector<string> survivors;
    for (auto module : modulePos) {
        if (moduleSurvives[module.second]) {
            survivors.push_back(module.second);
        }
    }
    reverse(all(survivors));

    int first = true;
    cout << survivors.size() << endl;
    for (auto survivor : survivors) {
        if (first) first = false;
        else cout << " ";
        cout << survivor;
    }
    cout << endl;
}

int main() {
    optimize;
    int T = 1;

    while (T--) solve();

    return 0;
}