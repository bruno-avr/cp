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

int main() {
    optimize;
    int v1, v2, v3;
    cin >> v1 >> v2 >> v3;

    if (v1 + 2*v2 + 3*v3 != 1029) {
        cout << "No" << endl;
        return 0;
    }

    for (int a1 = 0; a1 <= 14; a1++) {
        for (int a2 = 0; a2 <= 14; a2++) {
            for (int b1 = 0; b1 <= 14; b1++) {
                for (int b2 = 0; b2 <= 14; b2++) {
                    for (int c1 = 0; c1 <= 14; c1++) {
                        for (int c2 = 0; c2 <= 14; c2++) {
                            int two = max(7-abs(a1-a2), 0) * max(7-abs(b1-b2), 0) * max(7-abs(c1-c2), 0);
                            two += max(7-a1, 0) * max(7-b1, 0) * max(7-c1, 0);
                            two += max(7-a2, 0) * max(7-b2, 0) * max(7-c2, 0);

                            int three = max(7-max(a1, a2), 0) * max(7-max(b1, b2), 0) * max(7-max(c1, c2), 0);
                            two -= 3*three;

                            if (a1 == -1+7 && b1 == 2+7 && c1 == 6+7 && a2 == 1+7 && b2 == 5+7 && c2 == 3+7) {
                                cout << two << " " << three << endl;
                            }
                            if (v2 == two && v3 == three) {
                                cout << "Yes" << endl;
                                cout << "0 0 0 " << a1 << " " << b1 << " " << c1 << " " << a2 << " " << b2 << " " << c2 << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "No" << endl;
    
    return 0;
}