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
    long double whitespace, lowercase, uppercase, symbols;
    whitespace = lowercase = uppercase = symbols = 0;
    for (char &c : s) {
        if (c == '_') whitespace++;
        else if (c >= 'a' && c <= 'z') lowercase++;
        else if (c >= 'A' && c <= 'Z') uppercase++;
        else symbols++;
    }
    cout << fixed << setprecision(10) << (whitespace / s.size()) << endl; 
    cout << fixed << setprecision(10) << (lowercase / s.size()) << endl; 
    cout << fixed << setprecision(10) << (uppercase / s.size()) << endl; 
    cout << fixed << setprecision(10) << (symbols / s.size()) << endl; 
}

int main() {
    optimize;
    solve();

    return 0;
}