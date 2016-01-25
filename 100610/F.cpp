#include<bits/stdc++.h>
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

#define PB push_back
#define pb push_back
#define MP make_pair
#define F first
#define x first
#define S second
#define y second
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define DRT()  int t; cin>>t; while(t--)

#ifdef ONLINE_JUDGE
FILE *fin = freopen("frames.in","r",stdin);
FILE *fout = freopen("frames.out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

struct point{
    int x, y;
    point() {}
    point(int x_, int y_):
        x(x_), y(y_) {}
};

struct rect{
    point p0, p1;
    vector<point> allp;
    VI X,Y;
    rect() {}
    rect(point p0_, point p1_):
        p0(p0_), p1(p1_) {}

    void fix(){
        if(p0.x > p1.x)
            swap(p0.x, p1.x);
        if(p0.y > p1.y)
            swap(p0.y, p1.y);

        allp.pb(p0);
        allp.pb(p1);
        allp.pb(point(p0.x, p1.y));
        allp.pb(point(p1.x, p0.y));

        for(auto &i: allp){
            X.pb(i.x);
            Y.pb(i.y);
        }
    }

    void print(){
        trace(p0.x, p0.y, p1.x, p1.y);
    }

};

vector<rect> Apre;
rect Ain, Aout, Bin, Bout;

LL getarea(rect A, rect B){
    return 
        (LL)(max(0, -max(A.p0.y, B.p0.y) + min(A.p1.y, B.p1.y)))*
        (LL)(max(0, -max(A.p0.x, B.p0.x) + min(A.p1.x, B.p1.x)));
}

vector<rect> getrect(rect in, rect out){
    vector<rect> ret;
    ret.pb(rect(out.p0, point(out.p1.x, in.p0.y)));
    ret.pb(rect(point(out.p0.x, in.p1.y), out.p1));
    ret.pb(rect(point(out.p0.x, in.p0.y), point(in.p0.x, in.p1.y)));
    ret.pb(rect(point(in.p1.x, in.p0.y), point(out.p1.x, in.p1.y)));
    return ret;
}

LL place(vector<rect> A, vector<rect> B){
    LL ret=0;
    for(auto &i: A)
        for(auto &j: B)
            ret += getarea(i, j);
    return ret;
}

rect translate(rect cur, PII dist){
    return rect(point(cur.p0.x + dist.x, cur.p0.y + dist.y),
            point(cur.p1.x + dist.x, cur.p1.y + dist.y));
}

LL getans(PII trans){
    vector<rect> all=getrect(translate(Bin, trans), translate(Bout, trans));
    LL ans= place(all, Apre);
    return ans;
}

int main()
{
    cin >> Aout.p0.x >> Aout.p0.y;
    cin >> Aout.p1.x >> Aout.p1.y;
    cin >> Ain.p0.x >> Ain.p0.y;
    cin >> Ain.p1.x >> Ain.p1.y;


    cin >> Bout.p0.x >> Bout.p0.y;
    cin >> Bout.p1.x >> Bout.p1.y;
    cin >> Bin.p0.x >> Bin.p0.y;
    cin >> Bin.p1.x >> Bin.p1.y;


    Ain.fix();
    Aout.fix();
    Bin.fix();
    Bout.fix();

    Apre=getrect(Ain, Aout);

    LL ans=LLONG_MIN;
    VPII transl;

    VI dX1, dY1, dX2, dY2;

    for(auto i: Ain.X)
        dX1.pb(i);
    for(auto i: Aout.X)
        dX1.pb(i);
    for(auto i: Ain.Y)
        dY1.pb(i);
    for(auto i: Aout.Y)
        dY1.pb(i);

    for(auto i: Bin.X)
        dX2.pb(i);
    for(auto i: Bout.X)
        dX2.pb(i);
    for(auto i: Bin.Y)
        dY2.pb(i);
    for(auto i: Bout.Y)
        dY2.pb(i);

    for(auto x1: dX1)
        for(auto x2: dX2)
            for(auto y1: dY1)
                for(auto y2: dY2)
                    transl.pb({x1-x2, y1-y2});

    PII anst;

    for(auto i: transl){
        LL cur=getans(i);
        if(cur>ans)
            ans=cur, anst=i;
    }
    cout << ans << endl;
    cout << anst.F << " " << anst.S << endl;
    return 0;
}

