// karanaggarwal
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

#define sqr(x) ((x) * (x))

inline int cmp(double a, double b) 
{
   return (fabs(a-b) < eps) ? 0 : ((a < b) ? -1 : 1);
}
struct Point {
   double x, y;
   Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

   Point operator + (Point a) { return Point(x+a.x, y+a.y); }
   Point operator - (Point a) { return Point(x-a.x, y-a.y); }
   Point operator * (ll k) { return Point(x*k, y*k); }

   double operator * (Point a) { return x*a.x + y*a.y; } // dot product
   double operator % (Point a) { return x*a.y - y*a.x; } // cross product

   int cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }

#define Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }
   Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
#undef Comp

   Point conj() { return Point(x, -y); }
   double norm() { return x*x + y*y; }
};

int ccw(Point a, Point b, Point c) {
   return cmp((b-a)%(c-a),0);
}

ll area2(Point a, Point b, Point c) { return a%b + b%c + c%a; }


Point P[1001],L[1000];

int main()
{
   int n,m; cin>>n>>m;
   for(int i=0; i<n; i++)
      cin>>P[i].x>>P[i].y;
   for(int i=0; i<m; i++)
      cin>>L[i].x>>L[i].y;
   P[n] = P[0];

   return 0;	
}
