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

int getMax(vector<int> &v) {
    int currMax = -1;
    int currMin = INF;
    int maxDrop = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= currMax) {
            if (currMin != INF) {
                maxDrop = max(maxDrop, currMax-currMin);
            }
            currMax = v[i];
            currMin = INF;
        } else {
            currMin = min(currMin, v[i]);
        }
    }
    return maxDrop;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int maxDrop = getMax(v);
    reverse(all(v));
    maxDrop = max(maxDrop, getMax(v));
    
    cout << maxDrop << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}