#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
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
typedef vector<VI> VVI;
typedef vector< PII > VPII;

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

struct edge
{
    int x, y,c;
    edge() : x(0),y(0),c(0){}
    edge(int _x, int _y, int _c) : x(_x), y(_y), c(_c){}
    int node(int a) {return x^y^a;} 
};

edge E[50000];
VVI G;
int V[500];
int H[500];
int P[500];
int ans = 0;
int sum = 0;
int cst;

int dfs(int x, int p, int d)
{
    V[x] = true;
    H[x] = d; 
    int ret = H[x];
    int cnt = 0;
    for(auto y : G[x])
    {
        if(V[y]==true)
        {
            if(y==p)cnt++;
            if(y!=p or cnt>1)
                ret = min(ret,H[y]);
        }
        else
        {
            int mh = dfs(y,x,d+1); 
            if(mh <= d)
                ret = min(ret,mh);
            else
            {
                ans++; sum+=cst;
            }
        }
    }
    return ret;
}

bool cmp(edge a, edge b)
{
    return a.c < b.c;
}

int dad(int x)
{
    if(P[x]!=x) P[x] =dad(P[x]); return P[x];
}

bool unite(int x, int y)
{
    x = dad(x); y = dad(y);
    if(x==y)return false;
    P[x] = y; 
    return true;
}

int main()
{
    int n,m; cin>>n>>m;
    for(int i = 0; i<m; i++)
    {
        int x,y,c; cin>>x>>y>>c;
        x--; y--; 
        E[i] = edge(x,y,c);
    }
    for(int i = 0; i<n; i++) P[i] = i;
    sort(E,E+m,cmp);
    int j = 0;
    for(int i = 0; i<m; i++)
    {
        if(i!=m-1 and E[i].c==E[i+1].c)continue;
        G.clear();
        map<int,int> VV;
        for(int k = j; k<=i; k++)
        {
            VV[dad(E[k].x)];
            VV[dad(E[k].y)];
        }
        int N = VV.size();
        int c = 0;
        cst = E[i].c;
        for(auto &p : VV)p.S = c++;
        G.clear();
        G.resize(N);
        for(int k = 0; k<N; k++)V[k] = 0;
        for(int k = j; k<=i; k++)
        {
            int x = VV[dad(E[k].x)];
            int y = VV[dad(E[k].y)];
            if(x!=y)
            {
                G[x].PB(y); G[y].PB(x);
            }
        }
        for(int i=0; i<N; i++)
            if(V[i]==0)
                dfs(i,i,0);
        for(int k = j; k<=i; k++)unite(E[k].x, E[k].y);
        j = i+1;
    }
    cout<<ans<<" "<<sum<<endl;
    return 0;
}
