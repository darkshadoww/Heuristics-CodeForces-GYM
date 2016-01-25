//karanaggarwal
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

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

int n,s,t;
VPII G[1000];
int D[1000];
VPII nG[2000];
const int inf = 1100000000;

void djk(int src,int ty)
{

    for(int i =0; i<n; i++)D[i] = inf;
    D[src] = 0; queue<int> Q; Q.push(src);
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop(); int d = D[u];
        for(auto p : G[u])
        {
            int nd = d + p.S; int v = p.F;
            if(nd<D[v]){ D[v] = nd; Q.push(v);}
        }
    }
    for(int i = 0; i<n; i++)
        for(auto p : G[i])
        {
            int  j = p.F; 
            if(D[j]<D[i])
                nG[2*i + ty].PB({   2*j + (1-ty) , p.S });
        }
}

bool V[2000];
int IN[2000];
void dfs(int x)
{
    if(V[x])return;
    V[x] = true; 
    for(auto p : nG[x])
        dfs(p.F);
}

FILE *fin = freopen("journey.in","r",stdin);
FILE *fout = freopen("journey.out","w",stdout);

int main()
{
    cin>>n>>s>>t;
    s--; t--;

    for(int j = 0; j<2; j++)
    {
        for(int i = 0; i<n; i++)G[i].clear();
        int m ; si(m);
        for(int i =0; i<m; i++)
        {
            int a,b,l; si(a); si(b); si(l); a--; b--;
            G[a].PB({b,l});
            G[b].PB({a,l});
        }
        djk(t,j);
    }
    s*=2; 
    n*=2;
    dfs(s);
    int nc = 0;
    VI topo;
    queue<int> Q;
    for(int i = 0; i<n; i++)
    {
        if(V[i]==false) 
        {
            nG[i].clear(); continue;
        }
        VPII gg;
        nc++;
        for(auto p : nG[i])
        {
            if(V[p.F])
            {
                gg.PB(p); IN[p.F]++;
            }
        }
        nG[i] = gg;
    }
    for(int i = 0; i<n; i++)
        if(V[i] and IN[i]==0)
            Q.push(i);
    while(!Q.empty())
    {
        int x = Q.front(); Q.pop(); topo.PB(x);
        for(auto p : nG[x])
        {
            IN[p.F]--; 
            if(IN[p.F]==0)Q.push(p.F);
        }
    }
    if(topo.size() != nc)
    {
        cout<<-1<<endl; return 0;
    }
    VI dd(n);
    for(auto x : topo)
        for(auto p : nG[x])
            dd[p.F] = max(dd[p.F] , p.S + dd[x]);
    cout<<max(dd[2*t] , dd[2*t+1])<<endl;
    return 0;	
}
