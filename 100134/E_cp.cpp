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

//FILE *fin = freopen("exact.in","r",stdin);
//FILE *fout = freopen("exact.out","w",stdout);


vector< pair<long long,int> >  E[100000];
LL P[19];
int main()
{
    P[0] = 1;
    for(int i = 1; i<19; i++) P[i] = 10 * P[i-1];
    ios_base::sync_with_stdio(false);
    LL x;
    int N; cin>>x>>N;
    for(int i = 0; i<N; i++)
    {
        int p; LL y; 
        cin>>p>>y;
        E[i] = MP(P[p]*y,i);
    }
    VI TP;
    sort(E,E+N);
    LL cs = 0;
    int i = N-1;
    while(i>=0 and cs<x)
    {
        cs+=E[i].F; TP.PB(E[i].S+1); i--;
    }
    if(cs<x){cout<<-1<<endl; return 0;}
    cout<<TP.size()<<endl;
    for(auto c : TP) cout<<c<<" ";
    cout<<endl;
    return 0;
}
