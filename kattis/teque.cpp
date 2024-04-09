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
    int n, a;
    string inst;
    cin >> n;
    deque<int> firstHalf, secondHalf;
    f(i,0,n) {
        cin >> inst >> a;
        if (inst == "push_back") {
            secondHalf.push_back(a);
            if (secondHalf.size() > firstHalf.size()) {
                firstHalf.push_back(secondHalf.front());
                secondHalf.pop_front();
            }
        } else if (inst == "push_front") {
            firstHalf.push_front(a);
            if (firstHalf.size()-1 > secondHalf.size()) {
                secondHalf.push_front(firstHalf.back());
                firstHalf.pop_back();
            }
        } else if (inst == "push_middle") {
            secondHalf.push_front(a);
            if (secondHalf.size() > firstHalf.size()) {
                firstHalf.push_back(secondHalf.front());
                secondHalf.pop_front();
            }
        } else {
            if (a < firstHalf.size()) {
                cout << firstHalf[a] << endl;
            } else {
                cout << secondHalf[a - firstHalf.size()] << endl;
            }
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}