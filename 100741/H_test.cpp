#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>


#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
using namespace std;

inline int cmp(ll a, ll b) {
    return (a == b) ? 0 : ((a < b) ? -1 : 1);
}

#define MAXN 1000111
struct Point {
    ll x, y;
    int id;
    Point(ll x = 0.0, ll y = 0.0) : x(x), y(y) {}

    Point operator + (Point a) { return Point(x+a.x, y+a.y); }
    Point operator - (Point a) { return Point(x-a.x, y-a.y); }
    Point operator * (ll k) { return Point(x*k, y*k); }

    ll operator * (Point a) { return x*a.x + y*a.y; } // dot product
    ll operator % (Point a) { return x*a.y - y*a.x; } // cross product

    int cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }

    #define Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
    #undef Comp

    Point conj() { return Point(x, -y); }
    ll norm() { return x*x + y*y; }
};

int ccw(Point a, Point b, Point c) {
    return cmp((b-a)%(c-a),0);
}

ll area2(Point a, Point b, Point c) { return a%b + b%c + c%a; }

void ConvexHull(vector<Point> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<Point> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) > 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) < 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

double angle(Point a, Point o, Point b) { // angle AOB
    a = a - o; b = b - o;
    double res = acos((a * b) / sqrt(a.norm() * b.norm()));
    if (res < 0) res += 2 * acos(-1.0);
    return res;
}

int main() {
    ios :: sync_with_stdio(false);
    int n;
    while (scanf("%d", &n) == 1) {
        vector<Point> a, b;
        a.resize(n); b.resize(n);
        REP(i,n) {
            int x, y; scanf("%d%d", &x, &y);
            a[i] = Point(x, y);
            a[i].id = i + 1;

            b[i] = a[i];
        }
        ConvexHull(b);

        bool ok = false;
        FOR(i,2,n-1) if (ccw(a[0], a[1], a[i])) ok = true;

        if (!ok) {
            puts("No");
            continue;
        }

        int savei = -1;
        int saveu = -1, savev = -1;
        double best = -1;
        REP(i,1) {
            Point u = b[i];
            Point v = b[(i+1) % b.size()];
            REP(j,n)
                if (u.id != a[j].id && v.id != a[j].id && ccw(u, v, a[j])) {
                    double cur = max(angle(u, a[j], v), angle(v, a[j], u));
                    if (savei < 0 || cur > best) {
                        best = cur;
                        savei = j;
                        saveu = u.id;
                        savev = v.id;
                    }
                }
        }
        puts("Yes");
        printf("%d %d %d\n", a[savei].id, saveu, savev);
    }
}
