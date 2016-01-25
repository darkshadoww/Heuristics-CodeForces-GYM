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
//FILE *fin = freopen(stdin,"r",stdin);
//FILE *fout = freopen(stdout,"w",stdout);
#endif

pair<double,pair<double,double> > P[200];

double A[200][200];
int PX[200][200];

void print(int a, int b)
{
    if(PX[a][b]==-1)
    {
        cout<<b<<" ";
        return;
    }
    print(a, PX[a][b]);
    print(PX[a][b], b);
}

double dist(pair<double,pair<double,double> > A, pair<double,pair<double,double> > B)
{
    return sqrt(((A.F-B.F)*5)*((A.F-B.F)*5) + (A.S.F-B.S.F)*(A.S.F - B.S.F) + (A.S.S-B.S.S)*(A.S.S - B.S.S));
}

int main()
{
    memset(PX, -1, sizeof(PX));
    for(int i=0; i<200; i++)
        for(int j=0; j<200; j++)
            A[i][j]=1e12;
    //ios_base::sync_with_stdio(false);
    int n,m;
    si(n); si(m);
    for(int i=0; i<n; i++)
    {
        scanf("%lf %lf %lf", &P[i].F, &P[i].S.F, &P[i].S.S);
        A[i][i]=0;
    }
    for(int i=0; i<m; i++)
    {
        int a,b;
        string s;
        si(a);si(b);cin>>s;
        if(s=="walking" || s=="stairs")
        {
            A[a][b] = A[b][a] = dist(P[a], P[b]);
        }
        else if(s=="lift")
        {
            A[a][b] = A[b][a] = 1;
        }
        else
        {
            A[a][b] = 1;
            A[b][a] = dist(P[a], P[b])*3;
        }
    }
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(A[i][j] > A[i][k] + A[k][j])
                {
                    PX[i][j] = k;
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }
    int Q;
    si(Q);
    for(int q=0; q<Q; q++)
    {
        int a,b;
        si(a);si(b);
        cout<<a<<" ";
        print(a,b);
        cout<<endl;
    }
    return 0;
}


