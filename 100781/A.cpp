#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define si(n) scanf("%d",&n)
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

VI E[100000];
bool V[100000];

int D[100000];
int dia;
int dfs(int x)
{
    if(V[x])return 0;
    V[x] = true;
    VI cr; cr.PB(0); cr.PB(0);
    for(auto y : E[x])
       if(V[y]==false) 
           cr.PB(dfs(y));
    sort(cr.begin(), cr.end());
    reverse(cr.begin(), cr.end());
    dia = max(dia, cr[0] + cr[1]);
    return cr[0]+1;
}

int  diameter(int x)
{
    dia = 0;
    dfs(x);
    return dia;
}


int main()
{
    VI A;
    int n,m; 
    si(n); si(m);
    for(int i = 0; i<m; i++)
    {
        int x,y; si(x); si(y); E[x].PB(y); E[y].PB(x);
    }
    for(int i = 0; i<n; i++)
        if(V[i]==0)
            A.PB(diameter(i));
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    n = A.size();
    int ans = A[0];
    if(n>1)
        ans = max(ans, 1 + (A[0]+1)/2 + (A[1]+1)/2);
    if(n>2)
        ans = max(ans, 2 + (A[2]+1)/2 + (A[1]+1)/2);
    cout<<ans<<endl;
    return 0;
}
