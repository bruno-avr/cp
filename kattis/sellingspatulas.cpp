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

ll convert(string &s) {
    s.erase(s.find('.'),1);
    return stoi(s);
}

void solve(ll n) {
    vector<ll> res(1440, -8);
    string s;
    ll a;
    f(i,0,n) {
        cin >> a >> s;
        res[a] += convert(s);
    }
    ll total = 0;
    ll curr = 0;
    ll start = 0;
    ll currStart = 0;
    ll end = 1439;
    f(i,0,1440) {
        if (curr <= 0) {
            curr = 0;
            currStart = i;
        }
        curr += res[i];
        if (curr > total) {
            start = currStart;
            end = i;
            total = curr;
        } else if (curr == total) {
            if (i-currStart < end - start) {
                start = currStart;
                end = i;
            } else if (i-currStart == end - start) {
                if (currStart < start) {
                    start = currStart;
                    end = i;
                }
            }
        }
    }
    if (total == 0) {
        cout << "no profit" << endl;
    } else {
        string fim = to_string(total%100);
        while (fim.size() < 2) fim = "0" + fim;
        s = to_string(total/100) + "." + fim;
        cout << s << " " << start << " " << end << endl;
    }
}

int main() {
    optimize;
    ll n;
    while (cin >> n, n) solve(n);

    return 0;
}