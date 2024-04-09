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
    int n, a;
    cin >> n;
    stack<int> s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s1.push(a);
    }
    bool going = true;
    while (going) {
        going = false;
        while (s1.size()) {
            s2.push(s1.top());
            s1.pop();
            if (s1.size()) {
                if ((s1.top() + s2.top()) % 2 == 0) {
                    going = true;
                    s1.pop();
                    s2.pop();
                }
            }
        }
        swap(s1, s2);
    }
    cout << s1.size() << endl;
    
    
}

int main() {
    optimize;
    solve();

    return 0;
}