#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;

    Point(){}
    Point(ll a, ll b): x(a), y(b){}
};

Point sub(Point a, Point b) {
    Point p(a.x-b.x, a.y-b.y);
    return p;
}

ll cross(Point a, Point b) {
    return (a.x*b.y - a.y*b.x);
}

ll getBorderPoints(vector<Point> &v) {
    ll borderPoints = 0;
    for (ll i = 0; i < v.size(); i++) {
        Point a = sub(v[i], v[(i+1) % v.size()]);
        borderPoints += __gcd(abs(a.x), abs(a.y));
    }
    return borderPoints;
}

ll getArea(vector<Point> &v) {
    ll area = 0;
    for (ll i = 2; i < v.size(); i++) {
        area += cross(sub(v[i], v[0]), sub(v[i-1], v[0]));
    }
    return abs(area / 2);
}

ll getInsidePoints(ll area, ll borderPoints) {
    return area - borderPoints/2 + 1;
}

int main() {
    ll n;
    cin >> n;

    vector<Point> v(n);
    for(ll i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }

    ll borderPoints = getBorderPoints(v);

    ll area = getArea(v);
    ll insidePoints = getInsidePoints(area, borderPoints);

    cout << insidePoints << " " << borderPoints << endl;

    return 0;
}