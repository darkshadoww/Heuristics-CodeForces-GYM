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

#ifdef ONLINE_JUDGE
FILE *fin = freopen("cactus.in","r",stdin);
FILE *fout = freopen("cactus.out","w",stdout);
#endif

const int MN = 50000;
int D[MN],P[MN];
int S[MN];
VI E[MN];
int Dad[MN],CS[MN];
int N;
LL ans;
bool V[MN];
LL non_bridge;

int parent(int x){ if(Dad[x] != x) Dad[x] = parent(Dad[x]); return Dad[x];}
void unite(int x, int y)
{
    x = parent(x); y = parent(y);
    CS[x] += CS[y]; CS[y] = 0;
    Dad[y] = x;
}

LL f(int n)
{
    LL ret = n; ret*=(n-1); ret/=2;
    ret-=(n-1);
    return ret;
}


void pre()
{
    cin>>N;
    for(int i =0; i<N; i++)
    {
        V[i] = 0;
        E[i].clear();
        CS[i] =1;
        Dad[i] = i;
    }
    int p; cin>>p;
    while(p--)
    {
        int k; si(k);
        int x; si(x); k--; while(k--)
        {
            int y; si(y); E[x-1].PB(y-1); E[y-1].PB(x-1); x = y;
        }
    }
}

int dfs(int x, int p, int d)
{
    V[x] = true;
    P[x] = p;
    S[x] =1;
    D[x] = d;
    int ret = d;
    for(auto y : E[x])
    {
        if(V[y]==false)
        {
            int back = dfs(y,x,d+1);    
            S[x] += S[y];
            // bridge
            if(back>D[x]){
                unite(x,y);
                ans += ((LL)S[y] * (N-S[y])) - 1;
            }
            else
                ret = min(ret,back);
        }
        else if(D[y]<D[x]-1)
            ret = min(ret,D[y]);
    }
    return ret;
}


void dfs2(int x)
{
    V[x] = true;
    for(auto y : E[x])
    {
        if(V[y]==false)dfs2(y);
        else if(D[y]<D[x]-1)
        {
            int n = D[x] - D[y] + 1;
            int cr = x;
            int sum = 0;
            LL contri = non_bridge;
            do
            {
                sum += CS[parent(cr)];
//                trace(cr,sum);
                contri -= f(CS[parent(cr)]);
                cr = P[cr]; 
            }while(cr != -1 and D[cr]>=D[y]);
            contri += f(sum)-1;
//            trace(sum,n,contri);
            ans += n * contri;
        }
    }
}

int main()
{
    pre();
    dfs(0,-1,0);
    for(int i =0; i<N; i++) V[i] = false;
    for(int i =0; i<N; i++)
        if(Dad[i]==i)
            non_bridge += f(CS[i]);
  //  trace(non_bridge,ans);
    dfs2(0);
    cout<<ans<<endl;
    return 0;	
}
