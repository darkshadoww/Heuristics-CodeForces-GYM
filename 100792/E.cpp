#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
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

#define MAXN (1<<19)

LL fac[MAXN+10],inv[MAXN+10];
LL ar[MAXN+10];
LL pre[19][MAXN];

void add(LL &x, LL y){
    x += y;
    if(x>=MOD)x-=MOD;
}

void gen(){
    fac[0]=1;
    for(LL i=1; i<=MAXN; i++)
        fac[i]=(i*fac[i-1])%MOD;
    for(LL i=0; i<=MAXN; i++)
        inv[i]=mpow(fac[i],MOD-2)%MOD;
}

LL choose(LL n, LL r){
    if(n<0 or r<0 or n<r)return 0;
    return (((fac[n]*inv[r])%MOD)*inv[n-r])%MOD;
}

int main()
{
    gen();
    LL K,n;
    sl(K);
    n=1ll<<K;
    for(int i=1; i<=n; i++){
        sl(ar[i]);
        for(int level=0; level<K; level++){
            pre[level][i]=pre[level][i-1];
            add(pre[level][i], (ar[i]*choose(n-i-(1<<level),(1<<level)-1))%MOD);
        }
    }
    LL ans=0;
    for(int level=0; level<K; level++){
        LL val1=(((((1ll<<(K-level))*
                ((fac[1<<level]*fac[1<<level])%MOD))%MOD)*fac[n-(1<<(level+1))])%MOD);
        for(int j=1; j<=n; j++){
            LL val2=choose(n-j,(1<<level)-1);
            LL val3=(pre[level][j-1]*ar[j])%MOD;
            add(ans, (((val1*val2)%MOD)*val3)%MOD);
        }
    }
    printf("%lld\n",(ans*inv[n])%MOD);
    return 0;
}
