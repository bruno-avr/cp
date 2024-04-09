#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
#define all(x) x.begin(),x.end()
#define PI 3.14159265358979323846

int m, n, ax, ay, bx, by;
long double r;

long double calc(int numArc) {
    long double dist = ((long double)abs(ay - numArc)*r)/(long double)n;
    dist += ((long double)abs(by - numArc)*r)/(long double)n;

    long double halfCirclePer = PI*(r * (long double)numArc / (long double)n);
    dist += (halfCirclePer/(long double)m)*(long double)abs(ax - bx);
    return dist;
}

int main() {
    optimize;

    cin >> m >> n >> r;
    cin >> ax >> ay >> bx >> by;

    long double minDist = calc(n);
    for (int i = 0; i < n; i++) {
        minDist = min(minDist, calc(i));
    }

    cout << fixed << setprecision(10) << minDist << endl;

    return 0;
}