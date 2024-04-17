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
    int n, x, y;
    cin >> n;
    string orderType, aux;
    priority_queue<pair<int,int>> pqBuy, pqSell;
    int lastDeal = 0;
    f(i,0,n) {
        cin >> orderType >> x >> aux >> aux >> y;
        if (orderType == "buy") {
            pqBuy.push({y, x});
        } else {
            pqSell.push({-y, x});
        }
        while (pqSell.size() && pqBuy.size()) {
            auto ask = pqSell.top(); ask.first *= -1;
            auto bid = pqBuy.top();
            if (bid.first < ask.first) break;
            lastDeal = ask.first;

            pqBuy.pop();
            pqSell.pop();
            int items = min(bid.second, ask.second);
            if (bid.second - items) {
                pqBuy.push({bid.first, bid.second - items});
            }
            if (ask.second - items) {
                pqSell.push({-ask.first, ask.second - items});
            }
        }
        if (pqSell.size()) cout << pqSell.top().first*-1 << " ";
        else cout << "- ";
        if (pqBuy.size()) cout << pqBuy.top().first << " ";
        else cout << "- ";
        if (lastDeal) cout << lastDeal << endl;
        else cout << "-" << endl;
    }
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}