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
    string s;
    cin >> n >> s;
    int up, down, left, right;
    up = down = left = right = 0;
    vector<int> upV, downV, leftV, rightV;
    f(i,0,n) {
        if (s[i] == 'N') {
            upV.push_back(i);
            up++;
        }
        if (s[i] == 'S') {
            downV.push_back(i);
            down++;
        }
        if (s[i] == 'E') {
            leftV.push_back(i);
            left++;
        }
        if (s[i] == 'W') {
            rightV.push_back(i);
            right++;
        }
    }
    int diffUpDown = (max(up, down) - min(up, down));
    int diffLeftRight = (max(left, right) - min(left, right));
    if (diffUpDown % 2 || diffLeftRight % 2) {
        cout << "NO" << endl;
        return;
    }
    if (s == "WE" or s == "EW" or s == "SN" or s == "NS") {
        cout << "NO" << endl;
        return;
    }

    if (upV.size() && downV.size()) {
        s[upV.back()] = 'H';
        s[downV.back()] = 'H';
        upV.pop_back();
        downV.pop_back();
    } else if (leftV.size() && rightV.size()) {
        s[leftV.back()] = 'H';
        s[rightV.back()] = 'H';
        leftV.pop_back();
        rightV.pop_back();
    }

    while (upV.size() && downV.size()) {
        s[upV.back()] = 'R';
        s[downV.back()] = 'R';
        upV.pop_back();
        downV.pop_back();
    }
    while (leftV.size() && rightV.size()) {
        s[leftV.back()] = 'R';
        s[rightV.back()] = 'R';
        leftV.pop_back();
        rightV.pop_back();
    }
    while (upV.size()) {
        s[upV.back()] = 'R';
        upV.pop_back();
        s[upV.back()] = 'H';
        upV.pop_back();
    }
    while (downV.size()) {
        s[downV.back()] = 'R';
        downV.pop_back();
        s[downV.back()] = 'H';
        downV.pop_back();
    }
    while (leftV.size()) {
        s[leftV.back()] = 'R';
        leftV.pop_back();
        s[leftV.back()] = 'H';
        leftV.pop_back();
    }
    while (rightV.size()) {
        s[rightV.back()] = 'R';
        rightV.pop_back();
        s[rightV.back()] = 'H';
        rightV.pop_back();
    }
    string allR(s.size(), 'R');
    string allH(s.size(), 'H');
    if (s == allR or s == allH) {
        cout << "NO" << endl;
        return;
    }

    cout << s << endl;
}

int main() {
    optimize;
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}