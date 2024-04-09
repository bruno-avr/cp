#include "bits/stdc++.h"
using namespace std;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define ll long long
#define all(x) x.begin(),x.end()
#define PI 3.14159265358979323846

int main() {
    optimize;

    int m, n, ax, ay, bx, by;
    long double r;
    cin >> m >> n >> r;
    cin >> ax >> ay >> bx >> by;

    long double dist = ((long double)abs(ay - by)*r)/(long double)n;

    int diffX = abs(ax - bx);

    long double halfCirclePer = PI*(r * (long double)min(ay, by) / (long double)n);
    dist += (halfCirclePer/(long double)m)*(long double)diffX;

    cout << fixed << setprecision(10) << (long double)min(ay, by) / (long double)n << endl;

    return 0;
}