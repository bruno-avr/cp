#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
#define ld long long double
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

long double th = 0, tt = 0;
long double err = 1e-9;

long double p(vector<pair<long double,long double>> &av, vector<pair<long double,long double>> &dv, long double t) {
    long double ah = 0, dh = th;
    long double timeA = t, timeD = t;
    for(auto el : av) {
        if (el.second < timeA+err) {
            ah += el.first;
            timeA -= el.second;
        } else {
            ah += (timeA * el.first) / el.second;
            break;
        }
    }
    for(auto el : dv) {
        if ((long double) el.second < timeD+err) {
            dh -= el.first;
            timeD -= el.second;
        } else {
            dh -= ((long double) timeD * (long double) el.first) / (long double) el.second;
            break;
        }
    }
    return dh - ah;
}

long double bs(vector<pair<long double,long double>> &av, vector<pair<long double,long double>> &dv) {
    long double l = 0, r = tt;
    for (int i = 0; i < 100; i++) {
        long double m = (l+r) / 2;
        (p(av, dv, m) > 0) ? l = m : r = m;
    }
    return l;
}

void solve() {
    int a, d;
    long double h, t;
    cin >> a >> d;
    vector<pair<long double,long double>> av(a);
    vector<pair<long double,long double>> dv(d);
    f(i,0,a) {
        cin >> h >> t;
        av[i] = {h,t};
        th += h;
        tt += t;
    }
    f(i,0,d) {
        cin >> h >> t;
        dv[i] = {h,t};
    }
    cout << fixed << setprecision(10) << bs(av, dv) << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}