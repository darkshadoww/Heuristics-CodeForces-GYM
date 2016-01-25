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

#ifdef ONLINE_JUDGE
FILE *fin = freopen("black.in","r",stdin);
FILE *fout = freopen("black.out","w",stdout);
#endif

string A;

int main()
{
    int N,M,S,K;
    cin>>N>>M>>S>>K>>A;
    int first,last,cnt = 0;
    for(int i =0; i<M; i++)
    {
        if(A[i]=='*')
        {
            cnt++; last = i; if(cnt==1)first = i;
        }
    }
    if(cnt)
    {
        if(cnt !=S or last-first!=S-1)
        {
            cout<<"Impossible\n"; return 0;
        }
        if(S==1 or K==1 or K==N or S==N)
        {
            cout<<"Unique\n"; return 0;
        }
        cout<<"Ambiguous\n"; return 0;
    }
    if(K-1<S and N-K<S)
    {
            cout<<"Impossible\n"; return 0;
    }
    if(S!=M or (K-1>=S and N-K>=S))
    {
        cout<<"Ambiguous\n"; return 0;
    }
            cout<<"Unique\n"; return 0;

}


