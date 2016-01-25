#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define PB push_back
#define MP make_pair
#define x first
#define y second
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

FILE *fin = freopen("d.in","r",stdin);
FILE *fout = freopen("d.out","w",stdout);

//#define TRACE
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

typedef double D;
typedef pair<double,double> PDD;
const double PI = 3.14159265359;
const double eps = 1e-9;
PDD sub(PDD a, PDD b)
{
    PDD ret; ret.x = a.x - b.x; ret.y = a.y - b.y;
    return ret;
}
PDD rotate(PDD a, D k)
{
    PDD ret;
    ret.x = a.x * cos(k) - a.y*sin(k);
    ret.y = a.y * cos(k) + a.x * sin(k);
    return ret;
}
D dist(PDD a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

bool cmp(PDD a, PDD b)
{
    if(fabs(a.x - b.x) <= 1e-7)
        return a.y < b.y -eps;
    return a.x < b.x -eps;
}

bool eq(PDD a, PDD b)
{
    return fabs(a.x-b.x) + fabs(a.y-b.y) <= 1e-8;
}

int N;
PDD A[1000],B[1000],C[1000];

pair<bool,D> check(int i1, int i2)
{
    if(i1==i2)return {false,0.0};
    if( fabs(dist(A[1]) -  dist(sub(B[i1],B[i2]))) > 1e-7)return {false,0.0};

    trace(i1,i2);

    for(int i =0; i<N; i++)
        C[i] = sub(B[i],B[i1]);

    for(int i =0; i<N; i++)trace(i,B[i].x,B[i].y);
    for(int i =0; i<N; i++)trace(i,C[i].x,C[i].y);

    D k = atan2(C[i2].y, C[i2].x);
    trace(k);
    for(int i = 0; i<N;i++) C[i] = rotate(C[i],-k);
    sort(C,C+N,cmp);
    for(int i =0; i<N; i++)trace(i,C[i].x,C[i].y);
    for(int i =0; i<N; i++)
        if(eq(C[i],A[i])==false)
            return {false,0.0};
    return {true, k};
}

int main()
{
    si(N);
    D ans = PI;
    if(N<2)ans = eps;
    for(int i = 0; i<N; i++)
        cin>>A[i].x>>A[i].y;
    for(int i = 0; i<N; i++)
        cin>>B[i].x>>B[i].y;
    PDD t = A[0];
    for(int i = 0; i<N;i++) A[i] = sub(A[i],t);
    D k = atan2(A[1].y, A[1].x);
    for(int i = 0; i<N;i++) A[i] = rotate(A[i],-k);
    trace(k);
    
    sort(A,A+N,cmp);
    for(int i=0; i<N; i++)
        trace(i,A[i].x, A[i].y);
    for(int i =0; i<N; i++)
        for(int j = 0; j<N; j++)
            {
                pair<bool,D> a = check(i,j);
                trace(i,j,a.F,a.S);
                if(a.F)
                {
                    double d1 = a.S - k;
                    double d2 = k - a.S;
                    while(d1<0)d1+=2*PI;
                    while(d1>2*PI)d1-=2*PI;
                    while(d2<0)d2+=2*PI;
                    while(d2>2*PI)d2-=2*PI;
                    ans = min(ans,min(d1,d2));
                }
            }
    ans = max(ans,eps);
    printf("%.8lf\n",ans);
    return 0;
}


