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

FILE *fin = freopen("c.in","r",stdin);
FILE *fout = freopen("c.out","w",stdout);

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

map <pair<double, double>,int > m;
pair <double, double> points[1000];
typedef pair<double, double> PDD;

double A[1000][1000];

double dist(PDD A, PDD B)
{
    return sqrt((A.F-B.F)*(A.F-B.F)+(A.S-B.S)*(A.S-B.S));
}
int n;

double D[1000];
bool V[1000];

double ff()
{
    for(int i =0; i<n; i++)A[i][i] = 0;
    for(int i = 0; i<n; i++)
        D[i] = LLONG_MAX;
    D[0] = 0;
    while(V[n-1]==false)
    {
        int x = 0;
        while(V[x])x++;
        for(int y = x+1; y<n; y++)
            if(V[y]==false and D[y]<D[x])x = y;
        V[x] = true;
        for(int y = 0; y<n; y++)
            if(A[x][y]+D[x] < D[y])
                D[y] = D[x] + A[x][y];
    }
    return D[n-1];
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    double vw, vc;
    cin>>vw>>vc;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            A[i][j]=LLONG_MAX;
            if(i==j) A[i][j]=0;
        }
    }
    for(int i=0; i<n; i++)
    {
        cin>>points[i].F>>points[i].S;
        m[points[i]]=i;
        if(i!=0)
            A[i-1][i]=dist(points[i-1],points[i])/vw;
    }
    for(int i=1; i<n; i++)
    {
        if(points[i].S > points[i-1].S)
        {
            double miny = points[i].S;
            for(int j=i+1; j<n; j++)
            {
                if(points[j].S < points[i-1].S)
                {
                    double x,y = points[i-1].S;
                    x=(((points[j].F-points[j-1].F)/(points[j].S-points[j-1].S))*(y-points[j-1].S))+points[j-1].F;
                    A[i-1][j]=dist(points[i-1],MP(x,y))/vc + dist(MP(x,y), points[j])/vw;
                    break;
                }
                if(points[j].S<miny)
                {
                    miny = points[j].S;
                    double x,y = points[j].S;
                    x=(((points[i].F-points[i-1].F)/(points[i].S-points[i-1].S))*(y-points[i-1].S))+points[i-1].F;
                    A[i-1][j]=dist(points[i-1],MP(x,y))/vw + dist(MP(x,y), points[j])/vc;
                }
            }
        }
    }
    cout<<fixed<<setprecision(8)<<ff()<<endl;
    return 0;
}


