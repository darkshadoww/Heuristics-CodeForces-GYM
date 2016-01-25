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

typedef pair<LL,LL> PLL;

FILE *fin = freopen("caravan.in","r",stdin);
FILE *fout = freopen("caravan.out","w",stdout);

LL gcd(LL a, LL b)
{
    if(b)return gcd(b,a%b); return a;
}
PLL mn(PLL a, PLL b)
{
    if(a.F * b.S <= a.S * b.F)return a; return b;
}

PLL gen(PLL a)
{
    LL g = gcd(a.F,a.S); a.F/=g; a.S/=g; return a;
}
PII A[100000];
int main()
{
    int N; cin>>N;
    for(int i =0; i<N; i++)
        cin>>A[i].F>>A[i].S;
    sort(A,A+N);
    int last = 0;
    int tm = 0;
    for(int i = 0; i<N;i++)
    {
        A[i].F -= tm; A[i].S -= tm;
        int d = A[i].F - last;
        if(d>0)
        {A[i].F-=d; A[i].S-=d; tm += d;}
        last = A[i].S;
    }
    PLL ans = {1000000,1};
    for(int i =0; i<N; i++)
    {
        ans = mn( ans, {A[i].S -A[i].F,1} );
        ans = mn(ans,{A[i].S,i+1});
    }
    ans = gen(ans);
    cout<<ans.F<<"/"<<ans.S<<endl;
    return 0;
}


