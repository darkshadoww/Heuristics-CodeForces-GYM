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

#ifdef ONLINE_JUDGE
FILE *fin = freopen("generators.in","r",stdin);
FILE *fout = freopen("generators.out","w",stdout);
#endif

int K;
int ID[1000];
int MXID[10000];
int MNID[10000];

pair<bool,PII> process(int x, int a, int b,int c, int ii)
{
    memset(ID,-1,sizeof(ID));
    int id = 0;
    while(1)
    {
        if(ID[x]!=-1)break;
        ID[x]  = id++;
        x = (x * a + b) % c;
    }
    int mx = x; 
    for(int i =0; i<c; i++)
        if(ID[i]!=-1)mx = i;
    MXID[ii] = ID[mx];
    for(int j = mx-1; j>=0; j--)
        if(ID[j]!=-1 and (mx-j)%K)
        {
            MNID[ii]  = ID[j];
           return MP(true,MP(mx,mx-j));
        }
    return MP(false,MP(mx,0));
}


int main()
{
    int N;
    cin>>N>>K;
    int sum = 0;
    int mn = 1000;
    int mnp = -1;
    for(int i =0; i<N; i++)
    {
        int x,a,b,c;
        si(x); si(a); si(b); si(c);
        pair<bool,PII> p = process(x,a,b,c,i);
        sum += p.S.F;
        if(p.F and p.S.S<mn)
        {
                mn=p.S.S;
                mnp = i;
        }
    }
    if(sum%K)
    {
        cout<<sum<<endl;
        for(int i =0; i<N; i++)
            cout<<MXID[i]<<" "; cout<<endl; return 0;
    }

    if(mn==1000)
    {
        cout<<-1<<endl; return 0;
    }
    MXID[mnp] = MNID[mnp];
    sum -= mn;
        cout<<sum<<endl;
        for(int i =0; i<N; i++)
            cout<<MXID[i]<<" "; cout<<endl; return 0;

    return 0;
}


