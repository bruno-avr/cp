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
    int n;
    cin >> n;
    vector<int> arrows(1000005, 0);
    vector<int> v(n);
    f(i,0,n) {
        cin >> v[i];
    }
    int cont = 0;
    f(i,0,n) {
        if (arrows[v[i]]) {
            arrows[v[i]]--;
        } else {
            cont++;
        }
        arrows[v[i]-1]++;
    }
    cout << cont << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}