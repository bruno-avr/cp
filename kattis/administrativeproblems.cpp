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
    ll n, m, a, b, c, t;
    string e;
    cin >> n >> m;

    string name;

    unordered_map<string, tuple<ll, ll, ll>> carData;
    f(i,0,n) {
        cin >> name >> a >> b >> c;
        carData[name] = {a, b, c};
    }

    vector<tuple<ll,ll,ll>> events(m);
    unordered_map<string, pair<string, ll>> um;
    unordered_set<string> error;
    map<string, ll> costs;
    f(i,0,m) {
        cin >> t >> name >> e;
        if (e == "p") {
            string c;
            cin >> c;
            if (um.count(name)) error.insert(name);
            auto &[catalogPrice, pickupCost, costPerKM] = carData[c];
            costs[name] += pickupCost;
            um[name] = {c, t};
        } else if (e == "r") {
            ll d;
            cin >> d;
            if (um.count(name) == 0) error.insert(name);
            auto &[catalogPrice, pickupCost, costPerKM] = carData[um[name].first];
            costs[name] += costPerKM * d;
            um.erase(name);
        } else {
            ll s;
            cin >> s;
            if (um.count(name) == 0) error.insert(name);
            auto &[catalogPrice, pickupCost, costPerKM] = carData[um[name].first];
            costs[name] += (catalogPrice * s + 99)/100;
        }
    }
    for (auto el : costs) {
        if (um.count(el.first) || error.count(el.first)) cout << el.first << " INCONSISTENT" << endl;
        else cout << el.first << " " << el.second << endl;
    }
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}