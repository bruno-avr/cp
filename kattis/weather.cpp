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

ll fact[21];

void dfs(unordered_map<ll, ll> &totalBits, vector<vector<ll>> &children, ll pos, ll bits) {
    if (children[pos].size() == 0) {
        totalBits[pos] = bits;
        return;
    }
    for (auto &viz : children[pos]) {
        dfs(totalBits, children, viz, bits + 1);
    }
}

ll duplicate (vector<vector<ll>> &children, unordered_map<ll, tuple<ld, ll>> &probNumTimes, ll &idx, ll childId) {
    children.push_back({});
    ll thisId = idx++;
    auto &[oldProb, oldNumTimes] = probNumTimes[childId];
    // cout << idx << " " << children.size() << " " << childId << endl;
    for (auto &id : children[childId]) {
        ll a = duplicate(children, probNumTimes, idx, id);
        children[thisId].push_back(a);
    }
    return thisId;
}

void solve() {
    fact[1] = 1;
    for(ll i = 2; i < 21; i++) {
        fact[i] = fact[i-1] * i;
    }
    ll n;
    cin >> n;
    long double d;
    vector<ld> aux(4);
    f(i,0,4) {
        cin >> d;
        aux[i] = d;
    }

    ll idx = 0;
    ll totalTimes = 0;
    priority_queue<tuple<ld, ll, ll>> p;
    long double pss = 0;
    for(ll i = 0; i <= n; i++) {
        for(ll j = 0; j <= n-i; j++) {
            for(ll k = 0; k <= n-i-j; k++) {
                ll l = n-i-j-k;
                ld prob = 1;
                if (i) if (aux[0] == 0.0) continue; else prob *= powl(aux[0], i); 
                if (j) if (aux[1] == 0.0) continue; else prob *= powl(aux[1], j); 
                if (k) if (aux[2] == 0.0) continue; else prob *= powl(aux[2], k); 
                if (l) if (aux[3] == 0.0) continue; else prob *= powl(aux[3], l);
                ll numTimes = fact[n];
                if (i) numTimes /= fact[i]; 
                if (j) numTimes /= fact[j]; 
                if (k) numTimes /= fact[k];
                if (l) numTimes /= fact[l];
                // if (prob < 1e-8) continue;
                // cout << i << " " << j << " " << k << " " << l << " prob " << prob << " " << numTimes << endl;
                p.push({-prob, numTimes, idx++});
                // pss += prob * numTimes;
            }
        }
    }
    // cout << "pss " << pss << endl;
    unordered_map<ll, ll> totalBits;
    vector<vector<ll>> children(idx);
    ld total = 0;
    ll count = 0;
    unordered_map<ll, tuple<ld, ll>> probNumTimes;
    // while (!p.empty()) {
    //     auto [prob, numTimes, bitsUsed] = p.top(); p.pop();
    //     count += ceil(log2l(numTimes+1) - 0.000005l);
    //     cout << numTimes<< " " << count << endl;
    //     total += count * (prob * numTimes);
    // }
    ll maxBitsUsed;
    // if (p.size() == 1) total = 1;
    while (p.size() > 1) {
        auto [prob, numTimes, id] = p.top(); p.pop();
        // cout << -prob << " " << numTimes << " " << id << endl;
        if (numTimes % 2 == 0) {
            total -= prob * numTimes;
            p.push({2*prob, numTimes/2, idx++});
        } else {
            numTimes--;
            if (numTimes) {
                total -= prob * numTimes;
                p.push({2*prob, numTimes/2, idx++});
            }
            numTimes = 1;
            auto [prob2, numTimes2, id2] = p.top(); p.pop();
            total -= prob + prob2;
            p.push({prob + prob2, 1, idx++});
            if (numTimes2 > 1) {
                p.push({prob2, numTimes2-1, idx++});
            }

        }
    }
    // cout << idx << " " << children.size() << endl;
    // dfs(totalBits, children, idx-1, 0);

    // double probTotal = 0;
    // for (ll i = 0; i < children.size(); i++) {
    //     if (children[i].size() == 0) {
    //         auto &[prob, numTimes] = probNumTimes[i];
    //         total += prob * (ld)totalBits[i] * (ld)numTimes;
    //         // probTotal += prob*numTimes;
    //         // cout << prob << " " << numTimes << " " << totalBits[i] << endl ;
    //     }
    // }
                
    cout << fixed << setprecision(10) << (long double)total << endl;
    // cout << probTotal << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}