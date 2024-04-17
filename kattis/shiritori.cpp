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
    cin >> n;
    unordered_set<string> words;
    string word;
    cin >> word;
    words.insert(word);
    char last = word.back();
    f(i,1,n) {
        cin >> word;
        if (word[0] != last) {
            cout << "Player " << (i % 2 == 0 ? 1 : 2) << " lost" << endl;
            return;
        }
        if (words.count(word)) {
            cout << "Player " << (i % 2 == 0 ? 1 : 2) << " lost" << endl;
            return;
        }
        words.insert(word);
        last = word.back();
    }
    cout << "Fair Game" << endl;
}

int main() {
    optimize;
    solve();

    return 0;
}