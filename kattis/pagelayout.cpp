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

int maxArea;

bool hasConflict(tuple<int,int,int,int> &t1, tuple<int,int,int,int> &t2) {
    auto &[w1, h1, x1, y1] = t1;
    auto &[w2, h2, x2, y2] = t2;
    // cout << w1 << " " << h1 << " " << x1 << " " << y1 << endl;
    // cout << w2 << " " << h2 << " " << x2 << " " << y2 << endl;
    if (
        x1 < x2+w2 && w1+x1 > x2 &&
        y1 < y2+h2 && h1+y1 > y2
    ) return true;
    if (
        x2 < x1+w1 && w2+x2 > x1 &&
        y2 < y1+h1 && h2+y2 > y1
    ) return true;
    return false;
}

void func(vector<tuple<int,int,int,int>> &v, int pos, vector<tuple<int,int,int,int>> &curr, int area) {
    if (pos == v.size()) return;
    for (int i = pos; i < v.size(); i++) {
        bool conflict = false;
        for(auto &el : curr) {
            if (hasConflict(el, v[i])) {
                conflict = true;
                break;
            }
        }
        if (conflict) continue;
        curr.push_back(v[i]);
        auto &[w1, h1, x1, y1] = v[i];
        int newArea = area+(h1*w1);
        maxArea = max(maxArea, newArea);
        func(v,i+1,curr, newArea);
        curr.pop_back();
    }
}

void solve() {
    int n;
    while (cin >> n, n) {
        maxArea = 0;
        int w, h, x, y;
        vector<tuple<int,int,int,int>> v(n);
        f(i,0,n) {
            cin >> w >> h >> x >> y;
            v[i] = {w, h, x, y};
        }
        vector<tuple<int,int,int,int>> curr;
        func(v, 0, curr, 0);
        cout << maxArea << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}