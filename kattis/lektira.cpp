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
    string s;
    cin >> s;
    string minStr = "";
    f(i,0,s.size()-1) {
        string begin = s.substr(0, i+1);
        reverse(all(begin));
        f(j,i+1,s.size()-1) {
            string middle = s.substr(i+1, j-i);
            reverse(all(middle));
            string end = s.substr(j+1);
            reverse(all(end));
            string newStr = begin + middle + end;
            if (minStr == "") minStr = newStr;
            else minStr = min(newStr, minStr);
        }
    }
    cout << minStr << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}