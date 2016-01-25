#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

struct Point
{
    int x;
    int y;
    Point(int x_, int y_): x(x_), y(y_) {}
};

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

int dist(Point center, Point check){
    return (center.x-check.x)*(center.x-check.x) +  (center.y-check.y)*(center.y-check.y);
}

bool inside(Point center, Point check, int r){
    return dist(center, check)<= r*r;
}

const int offset=10000;
VI sensor[20001];
VI::iterator it;
vector< pair< Point, Point> > lines;

void init(){
    for(auto &i: sensor)
        i.clear();
    lines.clear();
}

int main()
{
    int t; 
    sd(t);
    while(t--){
        init();
        int s, r, w, p, x, y, u, v;
        sd(s),sd(r),sd(w),sd(p);

        for(int i=0; i<s; i++){
            sd(x), sd(y);
            sensor[x + offset].pb(y);
        }

        for(auto &i: sensor)
            sort(all(i));

        for(int i=0; i<w; i++){
            sd(x), sd(y), sd(u), sd(v);
            lines.pb({Point(x, y), Point(u, v)});
        }

        while(p--){
            sd(x),sd(y);
            Point product(x, y);
            set< PII > ans;

            for(int i=max(0,x-r+offset); i<=min(x+r+offset,20000); i++){
                it = lower_bound(all(sensor[i]), y-r);

                while(it != sensor[i].end() and *it <= y+r)
                {
                    Point cursensor(i-offset, *it);
                    if(inside(product,cursensor,r)==false)
                    {
                        it++; continue;
                    }
                    int intersect = 0;
                    for(auto &lin: lines){
                        if(doIntersect(product, cursensor, lin.F, lin.S))
                            intersect ++;
                    }
                    if(intersect > r)continue;
                    if(dist(product, cursensor) <= (r-intersect)*(r-intersect))
                        ans.insert({cursensor.x, cursensor.y});
                    it++;
                }
            }
            printf("%d ",(int)ans.size());
            for(auto &i: ans)
                printf("(%d,%d) ",i.F,i.S);
            printf("\n");
        }
    }
    return 0;
}


