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

int getNumberOfDigits(int n) {
    return (to_string(n)).size();
}

void solve() {
    int n, m, a, num0;
    cin >> n >> m;
    priority_queue<int> pq;
    int totalDigits = 0;
    f(i, 0, n) {
        num0 = 0;
        cin >> a;
        totalDigits += getNumberOfDigits(a);
        while (a%10 == 0) {
            num0++;
            a/=10;
        }
        pq.push(num0);
    }

    bool anna = true;
    while (!pq.empty()) {
        int curr = pq.top(); pq.pop();
        if (anna) totalDigits -= curr;
        anna = !anna;
    }

    if (totalDigits > m) cout << "Sasha" << endl;
    else cout << "Anna" << endl;    
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}