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
FILE *fin = freopen("commuting.in","r",stdin);
FILE *fout = freopen("commuting.out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

int P[200000];
int C[200001];
int N;

bool V[200000];

int B[200000];

VI ret_cycle(int x)
{
    VI ret; ret.PB(x);
    int st = x;
    V[x] =true;
    while(1)
    {
        x = P[x]; if(x!=st)ret.PB(x); else break;
        V[x] =true;
    }
    return ret;
}

VI divisors[200001];

int main()
{
    for(int i = 1; i<=200000; i++)
        for(int j = i; j<=200000; j+=i)
            divisors[j].PB(i);
    memset(C,-1,sizeof(C));
    si(N);
    for(int i = 0; i<N; i++){si(P[i]); P[i]--;}

    for(int i = 0; i<N; i++)
    {
        if(V[i])continue;
        VI cy = ret_cycle(i);
        int l = cy.size();
        int fd = i;
        if(C[l]==-1)C[l] = i;
        for(auto d : divisors[l])
            if(C[d]!=-1 and C[d]<fd)
                    fd = C[d];
        int v = fd;
        for(auto u : cy)
        {
            B[u] = v; v = P[v];
        }
    }
    for(int i = 0; i<N; i++) printf("%d ",B[i]+1); cout<<endl;

    return 0;
}

