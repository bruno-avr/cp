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

ll k, n;
bool adj[10][10];

// vector<ll> keepRes;

// void tsp(ll curr, ll val) {
//     if (val == 0) {
//         if (adj[curr][0]) {
//             set<set<ll>> edges;
//             edges.insert({0, keepRes[0]});
//             edges.insert({curr, 0});
//             // cout << "reeess" << endl;
//             // cout << "0 " << keepRes[0] << endl;
//             for (ll i = 1; i < keepRes.size(); i++) {
//                 edges.insert({keepRes[i], keepRes[i-1]});
//                 // cout << keepRes[i-1] << " " << keepRes[i] << endl;
//             }
//             // cout << keepRes.back() << " " << 0 << endl;
//             sres.insert(edges);
//         }
//         return;
//     }

//     for (ll i = val; i > 0; i -= LSOne(i)) {
//         ll next = __builtin_ctz(i) + 1;
//         ll nextVal = val - (1<<(next-1));
//         if (adj[curr][next]) {
//             keepRes.push_back(next);
//             tsp(next, nextVal);
//             keepRes.pop_back();
//         }
//     }
// }

pair<ll,ll> getPair(ll a, ll b) {
    pair<ll,ll> p{a,b};
    if (p.first > p.second) swap(p.first, p.second);
    return p;
}

void solve(ll c) {
    f(i,0,10) f(j,0,10) adj[i][j] = 1;
    cout << "Case #" << c << ": ";
    cin >> n >> k;
    ll u, y;
    f(i,0,k) {
        cin >> u >> y; u--; y--;
        adj[u][y] = 0;
        adj[y][u] = 0;
    }
    vector<ll> v(n-1);
    f(i,0,n-1) v[i] = i+1;
    unordered_set<ll> sres;
    do{
        set<ll> edges;
        if (adj[0][v[0]]) edges.insert(getPair(0, v[0]).first + getPair(0, v[0]).second*10);
        if (adj[0][v.back()]) edges.insert(getPair(0, v.back()).first + getPair(0, v.back()).second*10);
        for (ll i = 1; i < v.size(); i++) {
            if (adj[v[i-1]][v[i]]) edges.insert(getPair(v[i-1], v[i]).first + getPair(v[i-1], v[i]).second*10);
        }
        if (edges.size() == n) {
            ll aux = 1;
            ll thisR = 0;
            for (auto el : edges) {
                thisR += el * aux;
                aux *= 100;
            }
            sres.insert(thisR);
        }
    } while(next_permutation(all(v)));
    // for (auto el : sres) {
    //     cout << "ress" << endl;
    //     for (auto a : el) {
    //         for (auto b : a) {
    //             cout << b << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    // tsp(0, (1<<(n-1))-1);
    cout << sres.size()%9901 << endl;
}

int main() {
    optimize;
    ll T;
    cin >> T;

    ll c = 0;
    while (T--) solve(++c);

    return 0;
}