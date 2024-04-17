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
    int m;
    cin >> m;
    cin.ignore();
    unordered_map<string, unordered_set<string>> perUser;
    unordered_map<string, int> uses;
    set<pair<int, string>> res;
    unordered_set<string> users;
    f(i,0,m) {
        string line, word, user;
        getline(cin, line);
        stringstream ss;
        ss << line;
        ss >> user;
        users.insert(user);
        while (ss >> word) {
            perUser[word].insert(user);
            uses[word]++;
        }
    }
    for (auto &[word, numUses] : perUser) {
        if (numUses.size() == users.size()) res.insert({-uses[word], word});
    }
    if (res.size()) {
        for (auto &[numUses, word] : res) {
            cout << word << endl;
        }
    } else {
        cout << "ALL CLEAR" << endl;
    }
}

int main() {
    optimize;
    solve();

    return 0;
}