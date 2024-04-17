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

void execute(string &s) {
        string res(s);
        for (int i = 0; i < 5; i++) {
            s += s;
        }
        vector<int> v(s.size());
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            v[i] = s[i]-'0';
            sum += v[i];
        }
        if (sum % v.size() != 0) {
            cout << res << ": invalid # of balls" << endl;
            return;
        }

        set<int> leftHand, rightHand;
        
        for (int i = 0; i < v.size(); i++) {
            bool left = i%2 == 0;
            if (v[i] % 2 != 0) left = !left;
            int end = v[i]+i;
            if (left) {
                if (leftHand.count(end)) {
                    cout << res << ": invalid pattern" << endl;
                    return;
                }
                leftHand.insert(end);
            }
            else {
                if (rightHand.count(end)) {
                    cout << res << ": invalid pattern" << endl;
                    return;
                }
                rightHand.insert(end);
            }
        }
        int totalBalls = sum / v.size();
        cout << res << ": valid with " << totalBalls << " balls" << endl;
}

void solve() {
    string s;
    while (cin >> s) {
        execute(s);
    }
}

int main() {
    optimize;
    solve();

    return 0;
}