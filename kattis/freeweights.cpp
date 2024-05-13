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

bool p(vector<int> &row1, vector<int> &row2, int k) {
    vector<int> new1, new2;
    f(i,0,row1.size()) if (row1[i] > k) new1.push_back(row1[i]);
    f(i,0,row2.size()) if (row2[i] > k) new2.push_back(row2[i]);

    if (new1.size() % 2) return false;
    if (new2.size() % 2) return false;
    for (int i = 0; i < new1.size(); i += 2) {
        if(new1[i] != new1[i+1]) return false;
    }
    for (int i = 0; i < new2.size(); i += 2) {
        if(new2[i] != new2[i+1]) return false;
    }
    return true;
}

int bs(vector<int> &row1, vector<int> &row2) {
    int l = 0;
    int r = 1e9;
    while (l < r) {
        int m = l + ((r-l)>>1);
        (p(row1,row2,m)) ? r = m : l = m+1;
    }
    if (p(row1,row2,l)) return l;
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> row1(n), row2(n);
    f(i,0,n) {
        cin >> row1[i];
    }
    f(i,0,n) {
        cin >> row2[i];
    }
    cout << bs(row1, row2) << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}