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

int func(int a1, int b1, int c1, int a2, int b2, int c2) {
    int res = 1;
    res *= max(0, min(a1, a2) + 7 - max(a1, a2));
    res *= max(0, min(b1, b2) + 7 - max(b1, b2));
    res *= max(0, min(c1, c2) + 7 - max(c1, c2));
    return res;
}
int func(int a1, int b1, int c1, int a2, int b2, int c2, int a3, int b3, int c3) {
    int res = 1;
    res *= max(0, min({a1, a2, a3}) + 7 - max({a1, a2, a3}));
    res *= max(0, min({b1, b2, b3}) + 7 - max({b1, b2, b3}));
    res *= max(0, min({c1, c2, c3}) + 7 - max({c1, c2, c3}));
    return res;
}

bool mine (int v1, int v2, int v3) {
    if (v1 + 2*v2 + 3*v3 != 1029) {
        return false;
    }

    for (int a1 = 0; a1 <= 8; a1++) {
        for (int a2 = 0; a2 <= 8; a2++) {
            for (int b1 = 0; b1 <= 8; b1++) {
                for (int b2 = 0; b2 <= 8; b2++) {
                    for (int c1 = 0; c1 <= 8; c1++) {
                        for (int c2 = 0; c2 <= 8; c2++) {
                            int two = max(7-abs(a1-a2), 0) * max(7-abs(b1-b2), 0) * max(7-abs(c1-c2), 0);
                            two += max(7-a1, 0) * max(7-b1, 0) * max(7-c1, 0);
                            two += max(7-a2, 0) * max(7-b2, 0) * max(7-c2, 0);

                            int three = max(7-max(a1, a2), 0) * max(7-max(b1, b2), 0) * max(7-max(c1, c2), 0);
                            two -= 3*three;

                            if (v2 == two && v3 == three) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}
bool other (int v1, int v2, int v3) {
    for (int a2 = -1; a2 <= 7; a2++) {
        for (int b2 = -1; b2 <= 7; b2++) {
            for (int c2 = -1; c2 <= 7; c2++) {
                for (int a3 = -1; a3 <= 7; a3++) {
                    for (int b3 = -1; b3 <= 7; b3++) {
                        for (int c3 = -1; c3 <= 7; c3++) {
                            int nv3 = func(0, 0, 0, a2, b2, c2, a3, b3, c3);
                            int nv2 = func(0, 0, 0, a2, b2, c2) + func(0, 0, 0, a3, b3, c3) + func(a2, b2, c2, a3, b3, c3) -
                                      nv3 * 3;
                            int nv1 = 3 * 7 * 7 * 7 - nv2 * 2 - nv3 * 3;
                            if (v1 != nv1 or v2 != nv2 or v3 != nv3) continue;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    optimize;
    int total = 20;
    int v2 = 0;
    // for (int v1 = 0; v1 <= total; v1++) {
        // for (int v2 = 0; v2 <= total; v2++) {
            for (int v3 = 200; v3 >= 0; v3--) {
                int v1 = 1029 - 3*v3;
                if (mine(v1, v2, v3) != other(v1, v2, v3)) {
                    cout << v1 << " " << v2 << " " << v3 << " " << (mine(v1, v2, v3) ? "Sim" : "No") << endl;
                }
            }
        // }
    // }
    
    
}