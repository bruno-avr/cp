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
int numBubbleSortSwaps = 0;

void mergeSort(vector<int> &v, int s1, int e1, int s2, int e2) {
    // cout << s1 << " " << e1 << " - " << s2 << " " << e2 << endl;
    if (e1 - s1 > 1) mergeSort(v, s1, (s1+(e1-s1)/2), (s1+(e1-s1)/2), e1);
    if (e2 - s2 > 1) mergeSort(v, s2, (s2+(e2-s2)/2), (s2+(e2-s2)/2), e2);
    int c1 = s1, c2 = s2;
    queue<int> q;
    while (c1 != e1 || c2 != e2) {
        if (c1 == e1) {
            q.push(v[c2]);
            c2++;
        } else if (c2 == e2) {
            q.push(v[c1]);
            c1++;
        } else if (v[c1] <= v[c2]) {
            q.push(v[c1]);
            c1++;
        } else {
            numBubbleSortSwaps += e1 - c1;
            q.push(v[c2]);
            c2++;
        }
    }
    int i = s1;
    while(!q.empty()) {
        v[i++] = q.front();
        q.pop();
    }
}

void solve() {
    int n, a;
    cin >> n;
    vector<int> v(n);
    vector<int> v2(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; v[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> a; a--;
        v2[a] = i;
    }
    for (int i = 0; i < n; i++) {
        v[i] = v2[v[i]];
    }
    mergeSort(v, 0, n/2, n/2, n);
    
    cout << ((numBubbleSortSwaps % 2 == 0) ? "Possible" : "Impossible") << endl;

}

int main() {
    optimize;
    solve();

    return 0;
}