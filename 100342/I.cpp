#include<bits/stdc++.h>
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

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define DRT()  int t; cin>>t; while(t--)

#ifdef ONLINE_JUDGE
FILE *fin = freopen("travel.in","r",stdin);
FILE *fout = freopen("travel.out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

int N,M;
int D[20000];
int CS[20000];
int ANS[20000];
VI G[20000];

int dfs(int x, int d)
{
    D[x] = d;
    CS[x] = 1;
    int ret = d;
    VI cs;
    LL sm = 0;
    LL sm2 = 0;
    LL ans = 0;
    for(auto y : G[x])
    {
        if(D[y]==0)
        {
            int bk = dfs(y,d+1);
            CS[x] += CS[y]; 
            if(bk>=d){
                sm += CS[y];
                sm2 += CS[y] * CS[y];
            }
            ret = min(ret,bk);
        }
        else
            ret = min(ret,D[y]);
    }
    int rem = (N-1) - sm; sm = N-1; 
    sm2 += rem * rem;
    ans += sm * sm; ans -= sm2;
    ANS[x] = ans;
    return ret;
}


int main()
{
    si(N); si(M);
    while(M--)
    {
        int u,v; si(u); si(v); u--; v--; G[v].PB(u); G[u].PB(v);
    }
    dfs(0,1);
    for(int i  =0; i<N; i++)printf("%d\n",(ANS[i]/2) + N-1);
    return 0;
}

