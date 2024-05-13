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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ld> circles(n);
    vector<ld> houses(m);
    ld aux;
    for (int i = 0; i < n; i++) cin >> circles[i];
    for (int i = 0; i < m; i++) cin >> houses[i];
    for (int i = 0; i < k; i++) {
        cin >> aux;
        aux = sqrt((aux/2.0)*(aux/2.0) + (aux/2.0)*(aux/2.0));
        houses.push_back(aux);
    }
    m += k;
    sort(all(circles));
    sort(all(houses));
    int j = 0, res = 0;
    for (int i = 0; i < houses.size(); i++) {
        while (j < n && circles[j] <= houses[i]+0.000005) {
            j++;
        }
        if (j < n && circles[j] > houses[i]+0.000005) {
            res++;
            j++;
        }
    }
    cout << res << endl;
    
    
}

int main() {
    optimize;
    solve();

    return 0;
}