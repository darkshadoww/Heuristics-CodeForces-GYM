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

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b, a%b);
}

PII transform(int n, int m){
    int nn,mm;
    if(n<=0)nn=-m-2*n;
    else nn=m-2*n;
    mm=m;
    int gc=gcd(abs(nn), abs(mm));
    return {nn/gc, mm/gc};
}

PII org;

int a,b,c,d,r;
double ans;

pair<double, double> get(int n, int m){
    PII p=transform(n, m);
    double aa,bb,xx=(double)n/m;
    xx=xx*xx;

    if(n<=0)aa=a/(double)r, bb=((double)b+r*xx)/(double)r;
    else aa=c/(double)r, bb=((double)d + r*xx)/(double)r;

    if(p==org) return {aa, bb};
    pair< double, double> my=get(p.F, p.S);
    return {aa+bb*my.F, bb*my.S};
}

double get1(int n, int m){
    PII p=transform(n, m);
    if(mp(n, m)==org)
        return ans;

    double aa,bb,xx=(double)n/m;
    xx=xx*xx;

    if(n<=0)aa=a/(double)r, bb=((double)b+r*xx)/(double)r;
    else aa=c/(double)r, bb=((double)d + r*xx)/(double)r;

    return (double)aa + get1(p.F,p.S)*bb;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    int t;
    sd(t);
    while(t--){
        int n,m,np,mp;
        sd(n),sd(m),sd(a),sd(b),sd(c),sd(d),sd(r);

        int gc=gcd(n, m);
        n/=gc,m/=gc;

        map < PII, int > vis;
        np=n,mp=m;
        while(1){
            if(vis[{np, mp}])break;
            vis[{np, mp}]=1;
            PII p=transform(np, mp);
            np=p.F,mp=p.S;
        }

        org={np, mp};
        pair<double, double> x=get(np, mp);
        ans=x.F/(1-x.S);
        printf("%.9lf\n",get1(n, m));
    }
    return 0;
}

