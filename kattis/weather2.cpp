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

vector<int> res(4);

void dfs(vector<pair<int,int>> &v, int curr, int n) {
    if (curr < 4) {
        res[curr] = n;
    } else {
        if (v[curr].first != (long double)-1) dfs(v, v[curr].first, n+1);
        if (v[curr].second != (long double)-1) dfs(v, v[curr].second, n+1);
    }
}

ll fact[21];

void solve() {
    fact[1] = 1;
    for(int i = 2; i < 21; i++) {
        fact[i] = fact[i-1] * i;
    }
    int n;
    cin >> n;
    long double d;
    vector<long double> aux(4);
    f(i,0,4) {
        cin >> d;
        aux[i] = d;
    }

    priority_queue<tuple<long double, ll, ll>> p;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n-i; j++) {
            for(int k = 0; k <= n-i-j; k++) {
                int l = n-i-j-k;
                long double prob = 1;
                if (i) prob *= powl(aux[0], i); 
                if (j) prob *= powl(aux[1], j); 
                if (k) prob *= powl(aux[2], k); 
                if (l) prob *= powl(aux[3], l);
                ll div = 1;
                if (i) div *= fact[i]; 
                if (j) div *= fact[j]; 
                if (k) div *= fact[k]; 
                if (l) div *= fact[l];
                ll numTimes = fact[n]/div;
                cout << i << " " << j << " " << k << " " << l << " prob " << prob << " " << numTimes << endl;
                p.push({-prob, numTimes, 0});
            }
        }
    }
    long double total = 0;
    ll count = 0;
    // while (!p.empty()) {
    //     auto [prob, numTimes, bitsUsed] = p.top(); p.pop();
    //     count += ceil(log2l(numTimes+1) - 0.000005l);
    //     cout << numTimes<< " " << count << endl;
    //     total += count * (prob * numTimes);
    // }
    queue<tuple<long double, int, int>> q;
    int maxBitsUsed;
    while (!p.empty()) {
        auto [prob, numTimes, bitsUsed] = p.top(); p.pop();
        // total -= prob*(12-bitsUsed)*numTimes;
        // cout << prob << " " << numTimes << " " << bitsUsed << endl;
        if (p.empty()) {
            maxBitsUsed = bitsUsed;
            cout << "bits used: " << bitsUsed << endl;
            break;
        }
        if (numTimes > 1) {
            p.push({2*prob, numTimes/2, bitsUsed+1});
            if (bitsUsed == 0) q.push({prob, numTimes - (numTimes%2), 0});
            if (numTimes % 2) {
                p.push({prob, 1, bitsUsed});
            }
        } else {
            auto [prob2, numTimes2, bitsUsed2] = p.top(); p.pop();
            p.push({prob+prob2, 1, max(bitsUsed,bitsUsed2)+1});
            if (bitsUsed == 0) {
                q.push({prob, 1, bitsUsed2});
            }
            if (bitsUsed2 == 0) {
                q.push({prob2, 1, bitsUsed});
            }
            if (numTimes2 > 1) {
                p.push({prob2, numTimes2-1, bitsUsed});
            }
        }
    }

    while (!q.empty()) {
        auto [prob, numTimes, bitsUsed] = q.front(); q.pop();
        cout << prob << " " << numTimes << " " << maxBitsUsed-bitsUsed << endl;
        total -= prob*(maxBitsUsed-bitsUsed)*numTimes;

    }
                
    cout << "ans: " << total << endl;

    // vector<pair<int,int>> v(cont, {-1,-1});
    // f(i,4,7) {
    //     auto first = p.top(); p.pop();
    //     auto second = p.top(); p.pop();
    //     v[i].first = first.second;
    //     v[i].second = second.second;
    //     p.push({first.first + second.first, i});
    // }
    // dfs(v, 6, 0);
    // long double sum = 0;
    // f(i,0,4) {
    //     cout << res[i] << " " << aux[i] << " " << n <<  endl;
    //     f(j,0,n) {
    //         sum += aux[i] * (res[i]-j);
    //     }
    // }
    // cout << fixed << setprecision(10) << sum << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}