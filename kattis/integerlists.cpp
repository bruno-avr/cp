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
    string program, lista;
    int n;
    cin >> program >> n;
    cin.ignore();
    getline(cin, lista);
    string newLista = "";
    for (char &c : lista) {
        if (isdigit(c)) newLista += c;
        if (c == ',') newLista += ' ';
    }
    stringstream ss;
    ss << newLista;

    deque<int> res(n);
    f(i,0,n) {
        ss >> res[i];
    }

    bool left = true;
    for (char &c : program) {
        if (c == 'R') left = !left;
        else {
            if (!res.size()) {
                cout << "error" << endl;
                return;
            }
            if (left) res.pop_front();
            else res.pop_back();
        }
    }
    if (!left) reverse(all(res));
    cout << "[";
    f(i,0,res.size()) {
        if (i != 0) cout << ',';
        cout << res[i];
    }
    cout << "]" << endl;
    
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}