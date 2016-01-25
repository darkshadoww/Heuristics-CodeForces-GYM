#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>

#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define PB push_back
#define MP make_pair
#define x first
#define y second
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

#ifdef ONLINE_JUDGE
//FILE *fin = freopen(stdin,"r",stdin);
//FILE *fout = freopen(stdout,"w",stdout);
#endif

typedef double D;
typedef pair< double, double > PDD;

D PI; 

PDD operator+(PDD a, PDD b){
    return {a.x + b.x, a.y + b.y};
}

PDD operator-(PDD a, PDD b){
    return {a.x - b.x, a.y - b.y};
}

PDD operator/(PDD a, double c){
    return {a.x/c , a.y/c};
}

D polyarea(vector< PDD > p){
    D ret=0;
    int n=p.size();
    p.pb(p[0]);
    for(int i=0; i<n; i++){
        ret += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
    }
    return fabs(ret);
}

void rotate(PDD a, D theta)
{
    PDD ret;
    ret.x = a.x*cos(theta) - a.y * sin(theta);
    ret.y = a.y*cos(theta) + a.x * sin(theta);
    a=ret;
}

D dist(PDD a, PDD b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

class Circle{
    public:
    vector< vector< PDD > > rects;
    PDD center;
    D minorl, majorl;
    PDD major[2], minor[2];

    Circle(){
        for(int i=0; i<2; i++)
            cin >> major[i].x >> major[i].y;
        for(int i=0; i<2; i++)
            cin >> minor[i].x >> minor[i].y;

        int n;
        cin >> n;

        for(int i=0; i<n; i++){
            vector< PDD > rect(4);
            for(int j=0; j<4; j++)
                cin >> rect[j].x >> rect[j].y;
            rects.pb(rect);
        }

        majorl = dist(major[0], major[1]);
        minorl = dist(minor[0], minor[1]);
        if(majorl<minorl)
            swap(majorl, minorl), swap(major[0], minor[0]), swap(major[1], minor[1]);

    }

    void print(){
        trace(majorl, minorl);
        trace(center.x, center.y);
    }

    void translate(){
        center = (major[0] + major[1])/2;
        for(auto & i :rects)
            for(auto &j: i)
                j = j-center;

        for(auto &i: major)
            i = i- center;
        for(auto &i: minor)
            i = i- center;
        center = center-center;
    }

    void crotate(){
        PDD AB = major[1] - major[0];
        double theta = PI - atan2(AB.y , AB.x);
        for(auto & i :rects)
            for(auto &j: i)
                rotate(j,theta);

        for(auto &i: major)
            rotate(i,theta);
        for(auto &i: minor)
            rotate(i,theta);
    }

    void make_circle()
    {
        D ratio=majorl/minorl;
        for(auto & i :rects)
            for(auto &j: i)
                j.y *= ratio;

        for(auto &i: major)
            i.y *= ratio;
        for(auto &i: minor)
            i.y *= ratio;

        minorl*=ratio;
    }

    D getarea(){
        D ratio=100/majorl;
        D area=0;
        for(auto &i: rects){
            area += polyarea(i);
        }
        return area*ratio*ratio;
    }
};

VI A[100];


int main()
{
    PI = atan2(0, -1);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector < pair< double, int > > alll;
    VI ans(n);
    for(int i=0; i<n; i++){
        Circle my;
        my.translate();
        my.crotate();
        my.make_circle();
        alll.pb({my.getarea(), i});
    }

    sort(all(alll));
    int cnt=0;
    for(int i=0; i<n; i++){
        if(i and fabs(alll[i].x - alll[i-1].x) > 1e-4)
            cnt++;
        A[cnt].PB(alll[i].y);
        //if(n==33)
//            printf("%.7lf ", alll[i].x);
    }
    VI tp;
    for(int i =0; i<=cnt; i++)
    {
        sort(A[i].begin(),A[i].end());
        tp.PB(A[i][0]);
    }
    int i = 0;
    sort(tp.begin(),tp.end());
    for(auto c : tp) ans[c] = ++i;
    for(int i =0; i<=cnt; i++)
    {
        int x = A[i][0];
        for(auto c : A[i])
            ans[c] = ans[x];
    }
    for(auto &i: ans)
        cout << i << " ";
    cout << endl;
    return 0;
}


