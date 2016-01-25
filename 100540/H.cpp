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

#define N 10009
#define M 100009

VI graph[N];
int U[M],V[M];
bool isbridge[M];
int visited[N];
int parent[N];
int arr[N],T;

int adj(int u,int e){
    return U[e]==u?V[e]:U[e];
}
int dfs(int u,int edge)
{
    visited[u]=1;
    arr[u]=T++;
    int dbe = arr[u];
    for(int i=0;i<(int)graph[u].size();i++)
    {
        int e = graph[u][i];
        int w = adj(u,e);
        if(!visited[w])
            dbe = min(dbe,dfs(w,e));
        else if(e!=edge)
            dbe = min(dbe,arr[w]);
    }
    if(dbe == arr[u] && edge!=-1)
        isbridge[edge]=true;
    return dbe;
}

void init(){
    T=0;
    for(auto &i: graph)
        i.clear();
    memset(isbridge, 0, sizeof(isbridge));
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<N; i++)
        parent[i]=i;
}

int find(int x){
    if(parent[x]==x)return x;
    return parent[x]=find(parent[x]);
}

void merge(int x, int y){
    x = find(x); y = find(y); if(x!=y)parent[x] = y;
}
int main()
{
    while(1){
        init();

        int n,m,q,u,v;
        sd(n),sd(m),sd(q);
        if(n+m+q==0)return 0;

        for(int i=0; i<m; i++){
            sd(u),sd(v);
            u--,v--;
            U[i]=u;
            V[i]=v;
            graph[u].pb(i);
            graph[v].pb(i);
        }

        dfs(0,-1);

        for(int i=0; i<m; i++)
            if(isbridge[i])
                merge(U[i], V[i]);

        while(q--){
            sd(u),sd(v);
            u--,v--;
            if(find(u)==find(v))
                printf("Y\n");
            else printf("N\n");
        }
        printf("-\n");
    }
    return 0;
}


