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
#define MAXN 100008
#define LOGMAXN 20

VI adj[MAXN],radj[MAXN],badj[MAXN];
int high[MAXN],low[MAXN];
int N,T[MAXN];
int P[MAXN][LOGMAXN];
int L[MAXN];

void process3()
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; 1 << j < N; j++)
            P[i][j] = -1;
    for (i = 0; i < N; i++)
        P[i][0] = T[i];
    for (j = 1; 1 << j < N; j++)
        for (i = 0; i < N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

int query(int p, int q)
{
    int tmp, log, i;
    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;
    for (log = 1; 1 << log <= L[p]; log++);
    log--;
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];
    if (p == q)
        return p;
    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];
    return T[p];
}

void dfs1(int node, int p, int h){
    L[node]=h;
    T[node]=p;
    for(auto v: badj[node]){
        if(v==p)continue;
        dfs1(v,node,h+1);
    }
}

int vis[MAXN];
void dfs2(int node, int to){
    high[node]=to;
    vis[node]=1;
    for(auto v: adj[node]){
        if(L[v]<L[node])continue;
        dfs2(v, to);
    }
}

void dfs3(int node, int to){
    low[node]=to;
    vis[node]=1;
    for(auto v: radj[node]){
        if(L[v]<L[node])continue;
        dfs3(v, to);
    }
}
int main()
{
    int n,u,v;
    sd(n);
    N=n;
    for(int i=1; i<n; i++){
        sd(u),sd(v);
        u--,v--;
        adj[u].pb(v);
        radj[v].pb(u);
        badj[u].pb(v);
        badj[v].pb(u);
    }
    dfs1(0,-1,0);
    process3();
    for(int i=0; i<n; i++){
        if(not vis[i])
            dfs2(i,i);
    }
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++){
        if(not vis[i])
            dfs3(i,i);
    }
    /*
    for(int i=0; i<n; i++)
        trace(i,low[i]);
    for(int i=0; i<n; i++)
        trace(i,high[i]);
        */
    int m; sd(m);
    while(m--){
        sd(u),sd(v);
        u--,v--;
        int lca=query(u,v);
//        trace(u,v,lca);
        if(L[low[u]]<=L[lca] and L[high[v]]<=L[lca])
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
