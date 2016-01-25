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
#define x first
#define y second
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
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef vector< PLL > VPLL;


#ifdef ONLINE_JUDGE
FILE *fin = freopen("froggy.in","r",stdin);
FILE *fout = freopen("froggy.out","w",stdout);
#endif

LL DL[3000];
LL DR[3000];
VPLL P;
LL W;
int N;


inline LL sq(LL x){ return x*x;}

inline LL dist2(int i, int j)
{
    return sq(P[i].x -P[j].x) + sq(P[i].y - P[j].y);
}


void djk(LL D[])
{
    vector<bool> V(N,false);
    for(int i =0; i<N; i++)D[i] = sq(P[i].x);
    int explored = 0;
    while(explored<N)
    {
        int u = 0;
        while(V[u])u++;
        for(int i = u; i<N; i++)
            if(V[i]==false and D[i]<D[u])u = i;
        V[u] = true;explored++;
        for(int i =0; i<N; i++)
            if(V[i]==false)
                D[i] = min(D[i] , max(D[u],dist2(u,i)));
    }
}

void print(LL X)
{
    if(X%2)
        cout<<X/2<<".5";
    else 
        cout<<X/2<<".0";
}


void print(int i,int j)
{
    LL X = P[i].x + P[j].x;
    LL Y = P[i].y + P[j].y;
    print(X); cout<<" "; print(Y); cout<<"\n";
}



int main()
{

    cin>>W>>N;
    if(N==0)
    {
        print(W); cout<<" 0\n"; return 0;
    }
    for(int i = 0; i<N; i++)
    {
        LL u,v; cin>>u>>v;
        P.PB(MP(u,v));
        P.PB(MP(0,v));
        P.PB(MP(W,v));
    }
    N = P.size();
    djk(DL);
    for(int i =0; i<N; i++)
        P[i].x = W - P[i].x;
    djk(DR);
    for(int i =0; i<N; i++)
        P[i].x = W - P[i].x;
    PII ANS = {0,1};

    LL ans = 4*max(DL[0],DR[1]); ans = max(ans,dist2(0,1));
    for(int i =0; i<N; i++)
        for(int j = 0; j<N; j++)
        {
            if(i!=j)
            {
                LL nans  = 4 * max(DL[i],DR[j]);
                nans = max(nans, dist2(i,j));
  //              trace(nans,i,j);
                if(nans < ans)
                {
                    ans = nans;
                    ANS = {i,j};
                }
            }
        }
//    trace(ANS.F,ANS.S);
    print(ANS.F,ANS.S);
    return 0;
}


