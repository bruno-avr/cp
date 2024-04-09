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

int main() {
    optimize;
    unsigned ll n, t, a, b;
    cin >> n >> t;
    vector<unsigned ll> scores(n, 0);
    map<unsigned ll, unsigned ll> m;
    m[0] = n;
    for (unsigned ll i = 0; i < t; i++) {
        cin >> a >> b; a--;
        m[scores[a]]--;
        if (m[scores[a]] == 0) m.erase(scores[a]);
        scores[a] += b;
        m[scores[a]]++;
        cout << m.size() << endl;
    }

    return 0;
}