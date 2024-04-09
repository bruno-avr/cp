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
    int n, m;
    char c;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    f(i,0,n)
        f(j,0,m) {
            cin >> c;
            v[i][j] = (c == '.') ? 0 : INF;
        }
    
    int ring = 0;
    bool wcontinue = true;
    while (wcontinue) {
        ring++;
        wcontinue = false;
        f(i,0,n)
            f(j,0,m) {
                if (v[i][j] != INF) continue;
                wcontinue = true;
                int minN = INF;
                try { minN = min(minN, v.at(i-1).at(j)); } catch (const out_of_range &e) { minN = 0; }
                try { minN = min(minN, v.at(i+1).at(j)); } catch (const out_of_range &e) { minN = 0; }
                try { minN = min(minN, v.at(i).at(j+1)); } catch (const out_of_range &e) { minN = 0; }
                try { minN = min(minN, v.at(i).at(j-1)); } catch (const out_of_range &e) { minN = 0; }
                if (minN == ring-1) v[i][j] = ring;
            }
    }

    f(i,0,n) {
        f(j,0,m) {
            string s = v[i][j] == 0 ? "." : to_string(v[i][j]);
            while (s.size() < (ring < 10 ? 2 : 3)) {
                s = "." + s;
            }
            cout << s;
        }
        cout << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}