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
    int n, a, b, cont = 0;
    cin >> n;
    map<pair<int,int>, int> s;
    f(i,0,n) {
        cin >> a >> b;
        if (s[{a, b}]) {
            cont += s[{a, b}];
        }
        map<pair<int,int>, bool> visited;
        for (int j = 0; j <= 2018; j++) {
            int other = 2018*2018 - j*j;
            int res = floor(sqrt(other) + 0.0000005);
            if (res * res == other) {
                if (visited[{j,res}]) continue;
                visited[{j,res}] = true;
                visited[{res,j}] = true;
                s[{a+j, b+res}]++;
                s[{a+j, b-res}]++;
                if (j != 0) s[{a-j, b+res}]++;
                if (j != 0) s[{a-j, b-res}]++;
                s[{a+res, b+j}]++;
                if (j != 0) s[{a+res, b-j}]++;
                s[{a-res, b+j}]++;
                if (j != 0) s[{a-res, b-j}]++;
            }
        }
    }
    cout << cont << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}