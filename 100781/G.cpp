#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
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
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
using namespace std;

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

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

const int MX = 10001;
bitset <MX> A[MX];

vector <pair<int,int> > v;

int main()
{
    int g;
    scanf("%d", &g);
    for(int i=0; i<g; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        v.PB(MP(a,b));
    }
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        int x,y,r;
        scanf("%d %d %d", &x, &y, &r);
        for(int xx=max(0,x-r); xx<min(MX,x+r+1); xx++)
        {
            for(int yy=max(0,y-r); yy<min(MX,y+r+1); yy++)
            {
                if((xx-x)*(xx-x) + (yy-y)*(yy-y) <= r*r)
                    A[xx][yy]=true;
            }
        }
    }
    int ans=0;
    for(int i=0; i<v.size(); i++)
    {
        if(!A[v[i].F][v[i].S])
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}


