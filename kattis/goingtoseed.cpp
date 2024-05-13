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

int l1, r1, l2, r2, l3, r3;
int l[4];
int r[4];

void ask(int a, int b, int c, int d) {
    cout << "Q " << a << " " << b << " " << c << " " << d << endl;
    cout.flush();
}

int read() {
    int w1, w2;
    ask(l[0], r[1], l[1], r[2]);
    cin >> w1 >> w2;
    int where;
    if (w1 == 1 && w2 == 0) where = 0;
    else if (w1 == 1 && w2 == 1) where = 1;
    else if (w1 == 0 && w2 == 1) where = 2;
    else where = 3;
    return where;
}

void setV(int a, int b) {
    int n = b-a+1;
    if (n < 4) {
        int w1, w2;
        ask(a, a, a+1, a+1);
        cin >> w1 >> w2;
        if (w1) cout << "A " << a << endl;
        else if (w2) cout << "A " << a+1 << endl;
        else cout << "A " << a+2 << endl;
        exit(0);
    }
    if (n == 3) {
        l[0] = r[0] = a;
        l[1] = r[1] = a+1;
        l[2] = r[2] = b;
        l[3] = r[3] = b;
        return;
    }
    int delta1 = n/4;
    int delta2 = (n-delta1)/3;
    int delta3 = (n-delta1-delta2)/2;
    l[0] = a;
    r[0] = a+delta1-1;
    l[1] = r[0]+1;
    r[1] = r[0]+delta2;
    l[2] = r[1]+1;
    r[2] = r[1]+delta3;
    l[3] = r[2]+1;
    r[3] = b;
}

void solve() {
    int n, t;
    cin >> n;
    setV(1, n);

    while(1) {
        int where = read();
        for (int i = 0; i < 4; i++) {
            if (where == i) {
                if (l[i]==r[i]) {
                    cout << "A " << l[i] << endl;
                    return;
                }
                setV((l[i]-1 > 0) ? (l[i]-1) : l[i], (r[i]+1 < n) ? (r[i]+1) : r[i]);
            }
        }
    }
}
// void solve() {
//     int n, t;
//     cin >> n;
//     int delta = n/3;
//     int delta2 = (n-delta)/2;
//     l1 = 1, r1 = delta;
//     l3 = n-delta2+1, r3 = n;
//     l2 = r1+1, r2 = l3-1;

//     while(1) {
//         if (r3-l1+1 == 2) {
//             int w1, w2;
//             cout << "Q " << l1 << " " << l1 << " " << l1+1 << " " << l1+1 << endl;
//             cout.flush();
//             cin >> w1 >> w2;
//             if (w1) cout << "A " << l1 << endl;
//             else cout << "A " << l1+1 << endl;
//             return;
//         }
//         if (r3-l1+1 == 4) {
//             int w1, w2;
//             cout << "Q " << l1 << " " << l1+2 << " " << l1+1 << " " << l1+1 << endl;
//             cout.flush();
//             cin >> w1 >> w2;
//             if (!w1 && ! w2) cout << "A " << l1+3 << endl;
//             else if (w2) cout << "A " << l1+1 << endl;
//             else {
//                 cout << "Q " << max(1,l1-1) << " " << l1+1 << " " << l1+1 << " " << l1+3 << endl;
//                 cout.flush();
//                 cin >> w1 >> w2;
//                 if (w1 && w2) cout << "A " << l1+1 << endl;
//                 else if (w1) cout << "A " << max(1,l1-1) << endl;
//                 else cout << "A " << l1+3 << endl;
//             }
//             return;
//         }
//         const auto &[w1, w2, w3] = read();
//         if (w1) {
//             if (r1==l1) {
//                 cout << "A " << r1 << endl;
//                 return;
//             }
//             l1 = (l1-1 > 0) ? (l1-1) : l1;
//             r3 = (r1+1 < n) ? (r1+1) : r1;
//         } else if (w2) {
//             if (r2==l2) {
//                 cout << "A " << r2 << endl;
//                 return;
//             }
//             l1 = (l2-1 > 0) ? (l2-1) : l2;
//             r3 = (r2+1 < n) ? (r2+1) : r2;
//         } else {
//             if (r3==l3) {
//                 cout << "A " << r3 << endl;
//                 return;
//             }
//             l1 = (l3-1 > 0) ? (l3-1) : l3;
//             r3 = (r3+1 < n) ? (r3+1) : r3;
//         }
//         int items = r3 - l1 + 1;
//         delta = items/3;
//         delta2 = (items-delta)/2;
//         r1 = l1+delta-1;
//         l3 = l1+items-delta2;
//         l2 = r1+1, r2 = l3-1;
//         // cout << "l1 " << l1 << endl;
//         // cout << "r1 " << r1 << endl;
//         // cout << "l2 " << l2 << endl;
//         // cout << "r2 " << r2 << endl;
//         // cout << "l3 " << l3 << endl;
//         // cout << "r3 " << r3 << endl;
//         // cout << "items " << items << endl;
//         // cout << "delta " << delta << endl;
//     }
// }
// void solve() {
//     int n, t;
//     cin >> n;
//     l1 = 1, r1=n/2, l2=n/2+1, r2=n;

//     while(1) {
//         int missing;
//         if (r2 - l1 == 2) {
//             if (r1 - l1 == 1) {
//                 missing = l1;
//                 l1 = r1;
//             } else {
//                 missing = r2;
//                 r2 = l2;
//             }
//         }
//         const auto &[w1, w2] = read();
//         if (!w1 && !w2) {
//             cout << "A " << missing << endl;
//             return;
//         }
//         if (w2) {
//             if (r2==l2) {
//                 cout << "A " << r2 << endl;
//                 return;
//             }
//             l1 = (l2-1 > 0) ? (l2-1) : l2;
//             r2 = (r2+1 < n) ? (r2+1) : r2;
//         } else {
//             if (r1==l1) {
//                 cout << "A " << r1 << endl;
//                 return;
//             }
//             l1 = (l1-1 > 0) ? (l1-1) : l1;
//             r2 = (r1+1 < n) ? (r1+1) : r1;
//         }
//         r1 = l1+(r2-l1)/2;
//         l2 = l1+(r2-l1)/2+1;
//     }
// }

int main() {
    optimize;
    solve();

    return 0;
}