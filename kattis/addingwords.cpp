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
    string cmd, var, signal, var2, aux;
    int num;
    unordered_map<string, int> m1;
    unordered_map<int, string> m2;
    while (cin >> cmd) {
        if (cmd == "def") {
            cin >> var >> num;
            if (m1.find(var) != m1.end()) {
                m2.erase(m1[var]);
            }
            m1[var] = num;
            m2[num] = var;
        } else if (cmd == "calc") {
            vector<int> nums;
            vector<bool> adds;
            while (true) {
                cin >> var >> signal;
                if (m1.find(var) != m1.end()) nums.push_back(m1[var]);
                adds.push_back(signal == "+");
                cout << var << " " << signal << " ";
                if (signal == "=") break;
            }
            if (nums.size() != adds.size()) {
                cout << "unknown" << endl;
            } else {
                int sum = nums[0];
                f(i,1,nums.size()) {
                    if (adds[i-1]) sum += nums[i];
                    else sum -= nums[i];
                }
                if (m2.find(sum) == m2.end()) {
                    cout << "unknown" << endl;
                } else {
                    cout << m2[sum] << endl;
                }
            }
        } else {
            m1.clear();
            m2.clear();
        }
    }
}

int main() {
    optimize;
    solve();

    return 0;
}