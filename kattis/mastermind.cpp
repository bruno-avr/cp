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
    string s1, s2;
    cin >> n >> s1 >> s2;
    int r = 0, s = 0;
    f(i,0,s1.size()) {
        if (s1[i] == s2[i]) {
            s1 = s1.substr(0, i) + s1.substr(i+1, s1.size()-i-1);
            s2 = s2.substr(0, i) + s2.substr(i+1, s2.size()-i-1);
            r++;
            i--;
        }
    }
    unordered_map<char,int> um;
    f(i,0,s1.size()) {
        um[s1[i]]++;
    }
    f(i,0,s2.size()) {
        if (um[s2[i]]) {
            s++;
            um[s2[i]]--;
        }
    }
    cout << r << " " << s << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}