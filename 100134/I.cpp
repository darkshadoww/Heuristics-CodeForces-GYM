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
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
typedef double D;
typedef pair<D,PII> state;
vector<state> A;

double M[2] = {97.05276, 128.05858};
double W[100000];
bool isV[100000];
PII P[100000];

bool eq(D a, D b)
{
    if(fabs(a-b) < 1e-4)return true;
    return false;
}

VPII B;

int main()
{
    ios_base::sync_with_stdio(false);
    for(int i = 0; i<400; i++)
        for(int j = 0; j+i<=400; j++)
            A.PB({ i*M[0] + j*M[1],{i,j}});
    sort(A.begin(),A.end());
    int N; cin>>N;
    for(int i =0; i<N; i++)cin>>W[i];
    sort(W,W+N);
    double TT = W[N-1];
    int j = 0;
    for(int i = 0; i<N; i++)
    {
        while(j<A.size())
        {
            if(eq(W[i],A[j].F))
            {
                isV[i] = true;
                P[i] = A[j].S;
                B.PB(A[j].S);
                break;
            }
            else if(A[j].F < W[i])j++;
            else break;
        }
    }

    return 0;
}


