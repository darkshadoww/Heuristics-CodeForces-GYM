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
FILE *fin = freopen("landscape.in","r",stdin);
FILE *fout = freopen("landscape.out","w",stdout);
#endif

int N;
LL X; 

int A[100000];
int lH[100000];
int rH[100000];
LL PS[100000];

int L[100000],R[100000];

LL g(LL H, int t)
{
    LL ret = t;
    ret *= (2*H - t + 1);
    return ret/2;
}

bool f(LL H)
{
    for(int i = 0; i<N; i++)
        if(A[i]>=H)return true;
    memset(L,-1,sizeof(L));
    memset(R,-1,sizeof(R));
    int last_covered = 0;
    for(int j = 0; j<N; j++)
    {
        int r = A[j] + j - H;
        while(last_covered<=r and last_covered<j)
            R[last_covered++] = j;
    }

    last_covered = N-1;

    for(int j = N-1; j>=0; j--)
    {
        int r = H - (A[j]-j);
        while(last_covered>=r and last_covered>j)
            L[last_covered--] = j;
    }

    for(int i = 1; i<N-1; i++)
    {
        if(L[i]!=-1 and R[i]!=-1)
        {
            int r = R[i]-i;
            int l = i - L[i];
            LL req = g(H,l) + g(H,r) - H;
            req -= (PS[R[i]-1] - PS[L[i]]);
            if(req<=X)return true;
        }
    }
    return false;
}


int main()
{
    cin>>N;
    cin>>X;
    for(int i =0; i<N; i++)
        si(A[i]);
    PS[0] = A[0];
    for(int i = 1; i<N; i++)
        PS[i] = A[i] + PS[i-1];
    int l = 0;
    for(int i =0; i<N; i++)l = max(l,A[i]);
    
    lH[0] = A[0]; lH[N-1] = A[N-1];
    for(int i = 1; i<N-1;i++)
        lH[i] = max(A[i],1 + lH[i-1]);
    rH[0] = A[0]; rH[N-1] = A[N-1];
    for(int i = N-2; i>0;i--)
        rH[i] = max(A[i],1 + rH[i+1]);
    int h = l;
    for(int i = 0; i<N; i++){
        int pH = min(lH[i],rH[i]); 
        h = max(h,pH);
    }
    while(h>l)
    {
        int m = (l+h+1)/2;
        if(f(m))l = m; else h = m-1;
    }
    cout<<l<<endl;
    return 0;
}


