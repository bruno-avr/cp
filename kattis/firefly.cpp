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
    int n, h, a;
    cin >> n >> h;
    vector<int> bottom, top;
    f(i,0,n) {
        cin >> a;
        if (i%2) top.push_back(a);
        else bottom.push_back(a);
    }
    sort(all(top));
    sort(all(bottom));
    vector<int> height(h);
    int currHeight = 0;
    for (int i = 0; i < bottom.size(); i++) {
        f(j,currHeight,bottom[i]) {
            height[j] += bottom.size()-i;
        }
        currHeight = bottom[i];
    }

    currHeight = 0;
    for (int i = 0; i < top.size(); i++) {
        f(j,currHeight,top[i]) {
            height[h-1-j] += top.size()-i;
        }
        currHeight = top[i];
    }

    map<int,int> m;
    f(i,0,h) {
        m[height[i]]++;
    }
    cout << (*m.begin()).first << " " << (*m.begin()).second << endl;;
}

int main() {
    optimize;
    solve();

    return 0;
}